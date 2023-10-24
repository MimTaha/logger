project(Test)

add_executable(Test Test.cpp ColorPrinting_test.cpp)

target_include_directories(Test PRIVATE ../src)
