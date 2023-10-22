#ifndef TEST_COLORPRINTING_H
#define TEST_COLORPRINTING_H

#include "ColorPrinting.h"

#define my_printf(format, ...) \
    do{\
        printf(format, __VA_ARGS__);\
    }while(0)

class Test_ColorPrinting{
public:
    void t();
};

#endif //TEST_COLORPRINTING_H
