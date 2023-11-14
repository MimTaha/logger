#include <gtest/gtest.h>
#include "Logger.h"

TEST(Logger, justPrintTypesOfLogger) {
    Logger l;
    l.trace("This is a trace logg", 1000);
    l.debug("This is a debug logg", 0);
    l.info("This is a info logg", 1);
    l.warn("This is a warn logg", 10);
    l.error("This is a error logg", 100);
    l.fatal("This is a fatal logg", 0);
}

TEST(Logger, printWithArgs) {
    Logger l;
    l.trace("This is a trace logg %d", 1000, 12);
    l.debug("This is a debug logg %f", 0, 13);
    l.info("This is a info logg %s", 1, "1");
    l.warn("This is a warn logg %d", 10, 3);
    l.error("This is a error logg %d", 100, 1);
    l.fatal("This is a fatal logg %d", 0, 19);
}