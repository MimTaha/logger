#include <gtest/gtest.h>
#include "../include/ColorPrinting.h"

TEST(ColorPrinting, justPrint){
    ColorPrinting::print("Hello");
}

TEST(ColorPrinting, printWithColor){
    ColorPrinting::print("Hello", 30, 3);
}

TEST(ColorPrinting, printWithColorAndArgument){
    ColorPrinting::print("Hello%d", 0, 1, 12);
}