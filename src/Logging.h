#ifndef LOGGING_H
#define LOGGING_H

#include <fstream>
#include <string>
#include <map>
#include <ctime>
#include <chrono>
#include "ColorPrinting.h"

class Logging {
public:
    Logging();

    void trace(const std::string &message, int line, ...);

    void debug(const std::string &message, int line, ...);

    void info(const std::string &message, int line, ...);

    void warn(const std::string &message, int line, ...);

    void error(const std::string &message, int line, ...);

    void fatal(const std::string &message, int line, ...);

    void saveToFile(const std::string &message, const std::string &typeOfLogg, int line);

private:

    void printLog(const std::string &message, const std::string &typeOfLogg, int line, va_list args);

    void printTime();

    void printTypesOfLog(const std::string &typeOfLogg);

    void printLine(int line);

    void printMessage(const std::string &message, va_list args);

    std::map<std::string, int> colorOfAllTypeOfLog;
};

#endif //LOGGING_H