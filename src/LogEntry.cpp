#include "LogEntry.h"

LogEntry::LogEntry() {}

LogEntry::LogEntry(LogLevel level, int line)
    : _level(level), _line(line) {}

LogEntry::LogLevel LogEntry::getLevel() const {
    return _level;
}

void LogEntry::setLevel(LogLevel level) {
    _level = level;
}

int LogEntry::getLine() const {
    return _line;
}

void LogEntry::setLine(int line) {
    _line = line;
}

bool LogEntry::isActive() const {
    return _isActive;
}

void LogEntry::setIsActive(bool isActive) {
    _isActive = isActive;
}
