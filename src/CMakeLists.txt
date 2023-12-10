project(src)

add_library(src Logger.cpp
        ColorText.cpp
)
target_include_directories(src PUBLIC .)
