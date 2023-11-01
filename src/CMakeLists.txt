project(src)

add_library(src Logger.cpp)
target_include_directories(src PUBLIC .)
