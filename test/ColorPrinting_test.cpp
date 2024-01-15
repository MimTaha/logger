#include "ColorText.h"
#include <gtest/gtest.h>

TEST(ColorText, justGetText) {
    char *out = ColorText::getTxtColor(255, -1, "Hello");
    printf("%s", out);
}

TEST(ColorText, justPrint) {
    ColorText::print(255, -1, "Hello");
}

TEST(ColorText, getTextWithColor) {
    char *out = ColorText::getTxtColor(30, 3, "Hello");
    printf("%s", out);
}

TEST(ColorText, printWithColor) {
    ColorText::print(30, 3, "Hello");
}

TEST(ColorText, getTextWithColorAndArgument) {
    char *out = ColorText::getTxtColor(0, 1, "Hello%d", 12);
    printf("%s", out);
}

TEST(ColorText, printWithColorAndArgument) {
    ColorText::print(0, 1, "Hello%d", 12);
}
