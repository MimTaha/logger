#include <cstdio>
#include <cstdarg>
#include <cstring>

#include "ColorText.h"

void ColorText::print(const char *string, int textColor, int bgColor, va_list args) {
    char *text = getTxtColor(string, textColor, bgColor, args);
    printf("%s", text);
}

void ColorText::print(const char *string, int textColor, int bgColor, ...) {
    va_list args;
    va_start(args, string);
    print(string, textColor, bgColor, args);
    va_end(args);
}

char *ColorText::getTxtColor(const char *string, int textColor, int bgColor, va_list args) {
    char *out = new char[strlen(string) + 20];
    (bgColor == -1)
    ? sprintf(out, CP_SetColorText, textColor)
    : sprintf(out, CP_SetFullColor, textColor, bgColor);
    vsnprintf(out + strlen(out), strlen(out), string, args);
    sprintf(out + strlen(out), CP_ResetColor);
    return out;
}

char *ColorText::getTxtColor(const char *string, int textColor, int bgColor, ...) {
    va_list args;
    va_start(args, string);
    char *out = getTxtColor(string, textColor, bgColor, args);
    va_end(args);
    return out;
}
