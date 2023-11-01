#ifndef COLORPRINTING_H
#define COLORPRINTING_H

#include <cstdio>

#define ESC_Start "\033["
#define ESC_SetColorText ESC_Start "38;5;"
#define ESC_SetColorBackGround ESC_Start "48;5;"
#define ESC_End "m"
#define ESC_ResetColor ESC_Start "0" ESC_End
#define ESC_SetFullColorWitInt ESC_Start ESC_SetColorText "%d" ESC_End ESC_SetColorBackGround "%d" ESC_End

#define ESC_ColorPrinting(message, colorText, colorBackGround)\
    printf(ESC_SetFullColorWitInt message ESC_ResetColor, colorText, colorBackGround)

class ColorPrinting{
public:
private:
};

#endif // !COLORPRINTING_H
