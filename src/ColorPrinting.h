#ifndef COLORPRINTING_H
#define COLORPRINTING_H

#include <cstdio>

#define ESC_COLOR_TEXT "\033[38;5;"
#define ESC_COLOR_BKG "\033[48;5;"

#define setColorful ESC_COLOR_TEXT "%dm" ESC_COLOR_BKG "%dm"
#define resetColorful "\033[m"

#define colorPrinting(message, colorText, colorBkg, ...) printf_s(setColorful message resetColorful, colorText, colorBkg, __VA_ARGS__)

#endif // !COLORPRINTING_H
