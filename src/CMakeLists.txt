project(src)

add_library(src Logging.cpp
        ColorPrinting.cpp
)
target_include_directories(src PUBLIC .)
