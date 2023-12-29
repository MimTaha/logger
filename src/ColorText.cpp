#include <cstdio>
#include <cstring>

#include "ColorText.h"

void ColorText::print(int textColor, int bgColor, const char *string,va_list args) {
    printf("%s", getTxtColor(textColor, bgColor, string, args));
}

void ColorText::print(int textColor, int bgColor, const char *string,...) {
    va_list args;
    va_start(args, string);
    print(textColor, bgColor, string, args);
    va_end(args);
}

char *ColorText::getTxtColor(int textColor, int bgColor, const char *string, va_list args) {
    int sizeNeeded = snprintf(nullptr, 0, string, args);
    char *out = new char[sizeNeeded + strlen(_setFullColor) + strlen(_resetColor) + 1];
    (bgColor == -1)
        ?sprintf(out, _setColorText, textColor)
        :sprintf(out, _setFullColor, textColor, bgColor);
    vsprintf(out + strlen(out), string, args);
    strcat(out, _resetColor);
    return out;
}

char *ColorText::getTxtColor(int textColor, int bgColor, const char *string, ...) {
    va_list args;
    va_start(args, string);
    char *out = getTxtColor(textColor, bgColor, string, args);
    va_end(args);
    return out;
}

const char *ColorText::_setColorText = "\033[38;5;%dm";
const char *ColorText::_setColorBackGround = "\033[48;5;%dm";
const char *ColorText::_setFullColor = "\033[38;5;%dm\033[48;5;%dm";
const char *ColorText::_resetColor = "\033[0m";
