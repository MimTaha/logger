#ifndef LOGGING_H
#define LOGGING_H

#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include "ColorText.h"

class Logger {
public:
    Logger();

    enum LogLevel {
        TRACE,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL
    };

    void log(LogLevel level, int line, const std::string &funcName, const std::string &message, va_list args);

    void saveToFile(const std::string &typeOfLogg, const std::string &message, int line);

    void printLog(const std::string &message, LogLevel level, int line, va_list args);

private:

    char * getTimeTxtStruct();

    char * getLevelTxtStruct(LogLevel level);

    char * getLineTxtStruct(int line);

    char * getMessTxtStruct(const std::string &message, va_list args);

    static std::string logLevelToString(Logger::LogLevel level);

    static int logLevelToColor(LogLevel level);
};

#endif //LOGGING_H