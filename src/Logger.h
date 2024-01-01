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

    void log(const LogEntry &logEntry, const char *message, ...);

    void saveToFile(const char *message, va_list args);

    static Logger &getInstance(const char *logName);

  private:
    Logger(const char *logName);

    char *getLog(const char *message, va_list args);

    char *getTimeTxtStruct();

    char *getLevelTxtStruct();

    char *getLineTxtStruct();

    char *getMessTxtStruct(const char *message, va_list args);

    const char *logLevelToString(Logger::LogLevel level);

    int logLevelToColor(LogLevel level);

    static std::map<const char *, Logger> _instances;

    const LogEntry *_logEntry;
    const char *_logName;
};

#define makeLogger(logName) Logger instance = Logger::getInstance(logName)

#define LOG_TRACE(...)                                                         \
    instance.log(LogEntry(LogEntry::TRACE, __LINE__), __VA_ARGS__)
#define LOG_DEBUG(...)                                                         \
    instance.log(LogEntry(LogEntry::DEBUG, __LINE__), __VA_ARGS__)
#define LOG_INFO(...)                                                          \
    instance.log(LogEntry(LogEntry::INFO, __LINE__), __VA_ARGS__)
#define LOG_WARN(...)                                                          \
    instance.log(LogEntry(LogEntry::WARN, __LINE__), __VA_ARGS__)
#define LOG_ERROR(...)                                                         \
    instance.log(LogEntry(LogEntry::ERROR, __LINE__), __VA_ARGS__)
#define LOG_FATAL(...)                                                         \
    instance.log(LogEntry(LogEntry::FATAL, __LINE__), __VA_ARGS__)

#endif // LOGGING_H
