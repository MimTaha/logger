#ifndef LOGGING_H
#define LOGGING_H

#include <chrono>
#include <ctime>
#include <fstream>
#include <map>
#include <string>

#include "ColorText.h"
#include "LogEntry.h"

class Logger : private LogEntry {
  public:
    Logger();

    Logger(const char *logName);

    void log(const LogEntry &logEntry, const char *message, ...);

    void saveToFile(const char *message, va_list args);

    void setLowestLevel(LogEntry::LogLevel level);

  private:
    static Logger &getInstance(const char *logName);

    char *getLog(const char *message, va_list args);

    char *getTimeTxtStruct();

    char *getLevelTxtStruct();

    char *getLineTxtStruct();

    char *getMessTxtStruct(const char *message, va_list args);

    const char *logLevelToString(Logger::LogLevel level);

    int logLevelToColor(LogLevel level);

    static std::map<const char *, Logger> _instances;

    const LogEntry *_logEntry;
    LogEntry::LogLevel _lowestLevel;
};

#define makeLogger(logName) Logger instance = Logger::getInstance(logName)

#define Trace LogEntry(LogEntry::TRACE, __LINE__)
#define Debug LogEntry(LogEntry::DEBUG, __LINE__)
#define Info LogEntry(LogEntry::INFO, __LINE__)
#define Warn LogEntry(LogEntry::WARN, __LINE__)
#define Error LogEntry(LogEntry::ERROR, __LINE__)
#define Fatal LogEntry(LogEntry::FATAL, __LINE__)

#endif // LOGGING_H
