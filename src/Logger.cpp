#include <cstring>
#include "Logger.h"

Logger::Logger() {}


void
Logger::log(Logger::LogLevel level, int line, const std::string &funcName, const std::string &message, va_list args) {

}

void Logger::saveToFile(const std::string &typeOfLogg, const std::string &message, int line) {
    FILE *file = fopen("logging.txt", "a");
    if (file == NULL) {
        perror("Error opening file");
    fprintf(file, "%s", "out");
    fclose(file);
}

void Logger::printLog(const std::string &message, LogLevel level, int line, va_list args) {
    printf("%s %s ,%s ,%s\n", getTimeTxtStruct(), getLevelTxtStruct(level), getLineTxtStruct(line),
           getMessTxtStruct(message, args));
}

char *Logger::getTimeTxtStruct() {
    time_t timeNow = time(nullptr);
    char buffer[8];
    strftime(buffer, 9, "%T", localtime(&timeNow));
    return ColorText::getTxtColor(buffer, 38);
}

char *Logger::getLevelTxtStruct(LogLevel level) {
    char *out = ColorText::getTxtColor("%-5s", logLevelToColor(level), -1,
                                       logLevelToString(level).c_str());
    return out;
}

char *Logger::getLineTxtStruct(const int line) {
    char *textLine = ColorText::getTxtColor("line ", 12);
    char *amountLine = ColorText::getTxtColor("%-4d", 1, -1, line);
    strcat(textLine, amountLine);
    return textLine;
}

char *Logger::getMessTxtStruct(const std::string &message, va_list args) {
    char *textMessage = ColorText::getTxtColor("message ", 12);
    char *amountMessage = ColorText::getTxtColor(message.c_str(), 3, -1, args);
    strcat(textMessage, amountMessage);
    return textMessage;
}

std::string Logger::logLevelToString(Logger::LogLevel level) {
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
