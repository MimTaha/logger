project(Test)

add_executable(Test Test.cpp)

target_include_directories(Test PRIVATE ../src)
