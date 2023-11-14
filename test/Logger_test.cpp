#include <gtest/gtest.h>
#include "Logger.h"

TEST(Logger, justPrintTypesOfLogger) {
    Logger l;
    l.trace("This is a trace logg");
    l.debug("This is a debug logg");
    l.info("This is a info logg");
    l.warn("This is a warn logg");
    l.error("This is a error logg");
    l.fatal("This is a fatal logg");
}

TEST(Logger, a){

}