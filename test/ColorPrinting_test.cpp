#include <gtest/gtest.h>
#include "ColorText.h"

TEST(ColorText, justGetText){
    char *out = ColorText::getTxtColor("Hello");
    printf("%s", out);
}

TEST(ColorText, justPrint){
    ColorText::print("Hello");
}

TEST(ColorText, getTextWithColor){
    char *out = ColorText::getTxtColor("Hello", 30, 3);
    printf("%s", out);
}

TEST(ColorText, printWithColor){

    ColorText::print("Hello", 30, 3);
}

TEST(ColorText, getTextWithColorAndArgument){
    char *out = ColorText::getTxtColor("Hello%d", 0, 1, 12);
    printf("%s", out);

}

TEST(ColorText, printWithColorAndArgument){
    ColorText::print("Hello%d", 0, 1, 12);
}