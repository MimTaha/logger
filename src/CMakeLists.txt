project(src)

add_library(src Logger.cpp
        ColorText.cpp
        LogEntry.cpp
        LogEntry.h
)
target_include_directories(src PUBLIC .)
