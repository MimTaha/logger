#include "ColorPrinting.h"

void ColorPrinting::print(const char *string, int textColor, int bgColor, ...) {
    (bgColor == -1)
    ?printf(CP_SetColorText, textColor)
    :printf(CP_SetFullColor, textColor, bgColor);

    va_list args;
    va_start(args, string);
    vprintf(string, args);
    va_end(args);

    printf(CP_ResetColor);
}