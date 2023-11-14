#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <map>
#include <ctime>
#include <chrono>
#include "ColorPrinting.h"

class Logger{
public:
    Logger();

    void trace(const std::string &message, int line, ...);
    void debug(const std::string &message, int line, ...);
    void info(const std::string &message, int line, ...);
    void warn(const std::string &message, int line, ...);
    void error(const std::string &message, int line, ...);
    void fatal(const std::string &message, int line, ...);

private:
    void printLogg(const std::string &message, const std::string& typeOfLogg, int line, va_list args);

    void printTime();
    void printTypesOfLogg(const std::string &typeOfLogg);
    void printLine(int line);
    void printMessage(const std::string &message, va_list args);

    std::map<std::string, int> colorOfAllTypeOfLogg ;
};

#endif //LOGGER_H