#ifndef COLORPRINTING_H
#define COLORPRINTING_H

#include <cstdarg>

class ColorText {
  public:
    static void print(int textColor, int bgColor, const char *string,
                      va_list args);

    static void print(int textColor, int bgColor, const char *string, ...);

    static char *getTxtColor(int textColor, int bgColor, const char *string,
                             va_list args);

    static char *getTxtColor(int textColor, int bgColor, const char *string,
                             ...);

  private:
    static const char *_setColorText;
    static const char *_setColorBackGround;
    static const char *_setFullColor;
    static const char *_resetColor;
};

#endif // !COLORPRINTING_H
