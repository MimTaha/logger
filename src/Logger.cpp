#include "Logger.h"

Logger::Logger() {
    colorOfAllTypeOfLogg["trace"] = 245;
    colorOfAllTypeOfLogg["debug"] = 111;
    colorOfAllTypeOfLogg["info"] = 114;
    colorOfAllTypeOfLogg["warn"] = 223;
    colorOfAllTypeOfLogg["error"] = 214;
    colorOfAllTypeOfLogg["fatal"] = 196;
}

void Logger::trace(const std::string &message) {
    printTypesOfLogg("trace");
}
void Logger::debug(const std::string &message) {
    printTypesOfLogg("debug");
}
void Logger::info(const std::string &message) {
    printTypesOfLogg("info");
}
void Logger::warn(const std::string &message) {
    printTypesOfLogg("warn");
}
void Logger::error(const std::string &message) {
    printTypesOfLogg("error");
}
void Logger::fatal(const std::string &message) {
    printTypesOfLogg("fatal");
}

void Logger::printTypesOfLogg(const std::string &typeOfLogg) {
    ColorPrinting::print(typeOfLogg.c_str(), colorOfAllTypeOfLogg[typeOfLogg]);
    printf("\n");
}

void Logger::printLine(int line) {
    ColorPrinting::print("%d", 1, -1, line);
}
