#include <cstdio>
#include <iostream>
#include <string>

#include "ColorPrinting_test.h"

// Recursive function to process inputs
template <typename... Args>
void processInputs(const char message[], Args... rest) {
    printf(message, rest...);
}

#include "Logger.h"

int main(){
    processInputs("salam%d", 14);
    t();
    return 0;
}
