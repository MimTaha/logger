#include "ColorPrinting.h"

void ColorPrinting::print(const char *string, int textColor, int bgColor, va_list args) {
    (bgColor == -1)
    ?printf(CP_SetColorText, textColor)
    :printf(CP_SetFullColor, textColor, bgColor);

    vprintf(string, args);

    printf(CP_ResetColor);
}

void ColorPrinting::print(const char *string, int textColor, int bgColor, ...) {
    va_list args;
    va_start(args, string);
    print(string, textColor, bgColor, args);
    va_end(args);
}
