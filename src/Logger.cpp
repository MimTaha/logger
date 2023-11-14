#include "Logger.h"

std::map<std::string, int> Logger::colorOfAllTypeOfLogg;

Logger::Logger() {
    colorOfAllTypeOfLogg["trace"] = 245;
    colorOfAllTypeOfLogg["debug"] = 111;
    colorOfAllTypeOfLogg["info"] = 114;
    colorOfAllTypeOfLogg["warn"] = 223;
    colorOfAllTypeOfLogg["error"] = 214;
    colorOfAllTypeOfLogg["fatal"] = 196;
}

void Logger::trace(const std::string &message, const int line, ...) {
    va_list args;
    va_start(args, message.c_str());
    printLogg(message, "trace", line, args);
    va_end(args);
}

void Logger::debug(const std::string &message, const int line, ...) {
    va_list args;
    va_start(args, message.c_str());
    printLogg(message, "debug", line, args);
    va_end(args);
}

void Logger::info(const std::string &message, const int line, ...) {
    va_list args;
    va_start(args, message.c_str());
    printLogg(message, "info", line, args);
    va_end(args);
}

void Logger::warn(const std::string &message, const int line, ...) {
    va_list args;
    va_start(args, message.c_str());
    printLogg(message, "warn", line, args);
    va_end(args);
}

void Logger::error(const std::string &message, const int line, ...) {
    va_list args;
    va_start(args, message.c_str());
    printLogg(message, "error", line, args);
    va_end(args);
}

void Logger::fatal(const std::string &message, const int line, ...) {
    va_list args;
    va_start(args, message.c_str());
    printLogg(message, "fatal", line, args);
    va_end(args);
}

void Logger::printLogg(const std::string &message, const std::string& typeOfLogg, const int line, va_list args) {
    printTime();
    printf(" ");
    printTypesOfLogg(typeOfLogg);
    printf(" ,");
    printLine(line);
    printf(" ,");
    printMessage(message, args);
    printf("\n");
}

void Logger::printTime() {
    time_t timeNow = time(nullptr);
    char buffer[8];
    strftime(buffer, 9, "%T", localtime(&timeNow));
    ColorPrinting::print(buffer, 38);
}

void Logger::printTypesOfLogg(const std::string &typeOfLogg) {
    ColorPrinting::print("%-5s", colorOfAllTypeOfLogg[typeOfLogg], -1, typeOfLogg.c_str());
}

void Logger::printLine(const int line) {
    ColorPrinting::print("line ", 12);
    ColorPrinting::print("%-4d", 1, -1, line);
}

void Logger::printMessage(const std::string &message, va_list args) {
    ColorPrinting::print("message ", 12);
    ColorPrinting::print(message.c_str(), 3, -1, args);
}