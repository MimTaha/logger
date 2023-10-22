project(Test)

add_executable(Test Test.cpp Test_ColorPrinting.cpp)

target_include_directories(Test PRIVATE ../src .)
