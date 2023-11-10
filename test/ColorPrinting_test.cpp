#include "ColorPrinting_test.h"

void ColorPrinting_test::test(){
    ColorPrinting::print("Hello\n");
    ColorPrinting::print("Hello\n", 30, 3);
    ColorPrinting::print("Hello%d\n", 0, 1, 12);
}
