#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <map>
#include "ColorPrinting.h"

class Logger{
public:
    Logger();

    void trace(const std::string& message);
    void debug(const std::string& message);
    void info(const std::string& message);
    void warn(const std::string& message);
    void error(const std::string& message);
    void fatal(const std::string& message);

private:
    void printTypesOfLogg(const std::string &typeOfLogg);
    static void printLine(int line);

    std::map<std::string, int> colorOfAllTypeOfLogg ;
};

#endif //LOGGER_H