#include <cstdarg>
#include <cstdio>
#include <cstring>

#include "ColorText.h"
#include "Logger.h"

Logger::Logger() {}

void Logger::log(const LogEntry &logEntry, const char *message, ...) {
    if (logEntry.isActive()) {
        _logEntry = &logEntry;
        va_list args;
        va_start(args, message);
        printf("%s", getLog(message, args));
        va_end(args);
    }
}

void Logger::saveToFile(const char *message, va_list args) {
    FILE *file = fopen("logging.txt", "a");
    if (file == NULL)
        perror("Error opening file");

    fprintf(file, "%s", getLog(message, args));
    fclose(file);
}

Logger &Logger::getInstance(const char *logName) {
    auto it = _instances.find(logName);
    if (it != _instances.end()) {
        _instances[logName] = Logger(logName);
        return _instances[logName];
    } else
        return it->second;
}

char *Logger::getLog(const char *message, va_list args) {
    va_list argsCopy;
    va_copy(argsCopy, args);
    char *out =
        new char[strlen(getTimeTxtStruct()) + strlen(getLevelTxtStruct()) +
                 strlen(getLineTxtStruct()) +
                 strlen(getMessTxtStruct(message, argsCopy))];
    va_end(argsCopy);
    sprintf(out, "%s %s ,%s ,%s\n", getTimeTxtStruct(), getLevelTxtStruct(),
            getLineTxtStruct(), getMessTxtStruct(message, args));
    return out;
}

char *Logger::getTimeTxtStruct() {
    time_t timeNow = time(nullptr);
    char buffer[8];
    strftime(buffer, 9, "%T", localtime(&timeNow));
    return ColorText::getTxtColor(38, -1, buffer);
}

char *Logger::getLevelTxtStruct() {
    char *out =
        ColorText::getTxtColor(logLevelToColor(_logEntry->getLevel()), -1,
                               "%-5s", logLevelToString(_logEntry->getLevel()));
    return out;
}

char *Logger::getLineTxtStruct() {
    char *textLine = ColorText::getTxtColor(12, -1, "line ");
    char *amountLine =
        ColorText::getTxtColor(1, -1, "%-4d", _logEntry->getLine());
    strcat(textLine, amountLine);
    return textLine;
}

char *Logger::getMessTxtStruct(const char *message, va_list args) {
    char *textMessage = ColorText::getTxtColor(12, -1, "message ");
    char *amountMessage = ColorText::getTxtColor(2, -1, message, args);
    size_t totalSize = strlen(textMessage) + strlen(amountMessage) + 1;
    char *concatenatedString = new char[totalSize];
    strcpy(concatenatedString, textMessage);
    strcat(concatenatedString, amountMessage);
    delete[] textMessage;
    delete[] amountMessage;
    return concatenatedString;
}

const char *Logger::logLevelToString(Logger::LogLevel level) {
    switch (level) {
    case TRACE:
        return "TRACE";
    case DEBUG:
        return "DEBUG";
    case INFO:
        return "INFO";
    case WARN:
        return "WARN";
    case ERROR:
        return "ERROR";
    case FATAL:
        return "FATAL";
    default:
        return "UNKNOWN";
    }
}

int Logger::logLevelToColor(LogLevel level) {
    switch (level) {
    case TRACE:
        return 245;
    case DEBUG:
        return 111;
    case INFO:
        return 114;
    case WARN:
        return 223;
    case ERROR:
        return 214;
    case FATAL:
        return 196;
    default:
        return -1;
    }
}

std::map<const char *, Logger> Logger::_instances;
