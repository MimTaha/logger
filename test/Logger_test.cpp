#include <gtest/gtest.h>
#include "../include/Logger.h"

TEST(Logger, justPrintTypesOfLogger) {
    Logger logger;
    logger.trace("This is a trace logg", 1000);
    logger.debug("This is a debug logg", 0);
    logger.info("This is a info logg", 1);
    logger.warn("This is a warn logg", 10);
    logger.error("This is a error logg", 100);
    logger.fatal("This is a fatal logg", 0);
}

TEST(Logger, printWithArgs) {
    Logger logger;
    logger.trace("This is a trace logg %d", 1000, 12);
    logger.debug("This is a debug logg %f", 0, 13);
    logger.info("This is a info logg %s", 1, "1");
    logger.warn("This is a warn logg %d", 10, 3);
    logger.error("This is a error logg %d", 100, 1);
    logger.fatal("This is a fatal logg %d", 0, 19);
}

TEST(Logger, useLoggerMethodWithoutClass){
    Logger::trace("salam", __LINE__);
    Logger::debug("salam", __LINE__);
    Logger::info("salam", __LINE__);
    Logger::warn("salam", __LINE__);
    Logger::error("salam", __LINE__);
    Logger::fatal("salam", __LINE__);
}

TEST(Logger, useDefineLogg){
    loggTrace("salam");
    loggDebug("salam");
    loggInfo("salam");
    loggWarn("salam");
    loggError("salam");
    loggFatal("salam");
}