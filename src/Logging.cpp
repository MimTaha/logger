#include "Logging.h"

Logging::Logging() {
    colorOfAllTypeOfLog["trace"] = 245;
    colorOfAllTypeOfLog["debug"] = 111;
    colorOfAllTypeOfLog["info"] = 114;
    colorOfAllTypeOfLog["warn"] = 223;
    colorOfAllTypeOfLog["error"] = 214;
    colorOfAllTypeOfLog["fatal"] = 196;
}

void Logging::trace(const std::string &message, const int line, ...) {
    va_list args;
    va_start(args, message.c_str());
    printLog(message, "trace", line, args);
    va_end(args);
}

void Logging::debug(const std::string &message, const int line, ...) {
    va_list args;
    va_start(args, message.c_str());
    printLog(message, "debug", line, args);
    va_end(args);
}

void Logging::info(const std::string &message, const int line, ...) {
    va_list args;
    va_start(args, message.c_str());
    printLog(message, "info", line, args);
    va_end(args);
}

void Logging::warn(const std::string &message, const int line, ...) {
    va_list args;
    va_start(args, message.c_str());
    printLog(message, "warn", line, args);
    va_end(args);
}

void Logging::error(const std::string &message, const int line, ...) {
    va_list args;
    va_start(args, message.c_str());
    printLog(message, "error", line, args);
    va_end(args);
}

void Logging::fatal(const std::string &message, const int line, ...) {
    va_list args;
    va_start(args, message.c_str());
    printLog(message, "fatal", line, args);
    va_end(args);
}

void Logging::saveToFile(const std::string &message, const std::string &typeOfLogg, int line) {
    std::ofstream logFile;
    logFile.open("logging.txt", std::ios::out | std::ios::app);
    if(logFile.is_open()){
        logFile << message;
    }
    else{
        fatal("log file not open",12);
    }
}

void Logging::printLog(const std::string &message, const std::string& typeOfLogg, int line, va_list args) {
    printTime();
    printf(" ");
    printTypesOfLog(typeOfLogg);
    printf(" ,");
    printLine(line);
    printf(" ,");
    printMessage(message, args);
    printf("\n");
}

void Logging::printTime() {
    time_t timeNow = time(nullptr);
    char buffer[8];
    strftime(buffer, 9, "%T", localtime(&timeNow));
    ColorPrinting::print(buffer, 38);
}

void Logging::printTypesOfLog(const std::string &typeOfLogg) {
    ColorPrinting::print("%-5s", colorOfAllTypeOfLog[typeOfLogg], -1, typeOfLogg.c_str());
}

void Logging::printLine(const int line) {
    ColorPrinting::print("line ", 12);
    ColorPrinting::print("%-4d", 1, -1, line);
}

void Logging::printMessage(const std::string &message, va_list args) {
    ColorPrinting::print("message ", 12);
    ColorPrinting::print(message.c_str(), 3, -1, args);
}
