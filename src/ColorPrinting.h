#ifndef COLORPRINTING_H
#define COLORPRINTING_H

#include <cstdio>
#include <cstdarg>

#define CP_Start "\033["
#define CP_End "m"
#define CP_SetColorText CP_Start "38;5;%d" CP_End
#define CP_SetColorBackGround CP_Start "48;5;%d" CP_End
#define CP_ResetColor CP_Start "0" CP_End
#define CP_SetFullColor CP_SetColorText CP_SetColorBackGround

class ColorPrinting {
public:
    static void print(const char *string, int textColor = 250, int bgColor = -1, ...);

private:
};

#endif // !COLORPRINTING_H
