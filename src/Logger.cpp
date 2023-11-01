#include "Logger.h"
#include <iostream>

template <typename... Args>
void myVariadicFunction(Args... args) {
    // Use a fold expression to print all the arguments
    (std::cout << ... << args);
    std::cout << std::endl;
}

void t(){
    std::cout << "salam";
}
