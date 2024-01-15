#ifndef LOGGER_LOGENTRY_H
#define LOGGER_LOGENTRY_H

struct LogEntry {
  public:
    enum LogLevel { TRACE, DEBUG, INFO, WARN, ERROR, FATAL };

    LogEntry();
    LogEntry(LogLevel level, int line);

    LogLevel getLevel() const;

    void setLevel(LogLevel level);

    int getLine() const;

    void setLine(int line);

  private:
    LogLevel _level;
    int _line;
};

#endif // LOGGER_LOGENTRY_H
