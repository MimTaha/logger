#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <map>
#include <ctime>
#include <chrono>
#include "ColorPrinting.h"

class Logger {
public:
    Logger();

    static void trace(const std::string &message, int line, ...);

    static void debug(const std::string &message, int line, ...);

    static void info(const std::string &message, int line, ...);

    static void warn(const std::string &message, int line, ...);

    static void error(const std::string &message, int line, ...);

    static void fatal(const std::string &message, int line, ...);

private:
    static void printLogg(const std::string &message, const std::string &typeOfLogg, int line, va_list args);

    static void printTime();

    static void printTypesOfLogg(const std::string &typeOfLogg);

    static void printLine(int line);

    static void printMessage(const std::string &message, va_list args);

    static std::map<std::string, int> colorOfAllTypeOfLogg;
};

#define loggTrace(message, ...) Logger::trace(message, __LINE__, ##__VA_ARGS__)
#define loggDebug(message, ...) Logger::debug(message, __LINE__, ##__VA_ARGS__)
#define loggInfo(message, ...) Logger::info(message, __LINE__, ##__VA_ARGS__)
#define loggWarn(message, ...) Logger::warn(message, __LINE__, ##__VA_ARGS__)
#define loggError(message, ...) Logger::error(message, __LINE__, ##__VA_ARGS__)
#define loggFatal(message, ...) Logger::fatal(message, __LINE__, ##__VA_ARGS__)

#endif //LOGGER_H