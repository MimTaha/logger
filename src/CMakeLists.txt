project(src)

add_library(src Logger.cpp
        ColorPrinting.cpp)
target_include_directories(src PUBLIC .)
