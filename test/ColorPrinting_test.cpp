#include "ColorPrinting_test.h"
#include <cstdio>

void ColorPrinting_test::test(){
    ESC_ColorPrinting("salam welcom\n", 12, 13);
    ESC_ColorPrinting("salam welcom\n\n", 18, 25);
    printf("salam");
}
