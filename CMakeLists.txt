cmake_minimum_required(VERSION 3.25.1)

project(logger)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_definitions(-DSOME_DEFINITION)

add_subdirectory(src)
add_subdirectory(test)
#add_subdirectory(Google_tests)
