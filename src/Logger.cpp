#include <cstring>
#include <cstdarg>

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

    printf("%s", getLog(message, args));
    fclose(file);
}

Logger &Logger::getInstance(const char *logName) {
    auto it = _instances.find(logName);
    if (it != _instances.end()) {
        return it->second;
    } else {
        _instances[logName] = Logger(logName);
        return _instances[logName];
    }
}

Logger::Logger(const char *logName) : _logName(logName) {}

char *Logger::getLog(const char *message, va_list args) {
    char *out = new char[strlen(message) + 20];
    sprintf(out, "%s %s ,%s ,%s\n", getTimeTxtStruct(), getLevelTxtStruct(), getLineTxtStruct(),
            getMessTxtStruct(message, args));
    return out;
}

char *Logger::getTimeTxtStruct() {
    time_t timeNow = time(nullptr);
    char buffer[8];
    strftime(buffer, 9, "%T", localtime(&timeNow));
    return ColorText::getTxtColor(buffer, 38);
}

char *Logger::getLevelTxtStruct() {
    char *out = ColorText::getTxtColor("%-5s", logLevelToColor(_logEntry->getLevel()), -1,
                                       logLevelToString(_logEntry->getLevel()));
    return out;
}

char *Logger::getLineTxtStruct() {
    char *textLine = ColorText::getTxtColor("line ", 12);
    char *amountLine = ColorText::getTxtColor("%-4d", 1, -1, _logEntry->getLine());
    strcat(textLine, amountLine);
    return textLine;
}

char *Logger::getMessTxtStruct(const char *message, va_list args) {
    char *textMessage = ColorText::getTxtColor("message ", 12);
    char *amountMessage = ColorText::getTxtColor(message, 3, -1, args);
    strcat(textMessage, amountMessage);
    return textMessage;
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
