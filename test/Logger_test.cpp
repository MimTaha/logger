#include <gtest/gtest.h>
#include <cstring>
#include "Logger.h"

TEST(Logger, justPrintTypesOfLogger) {
    Logger logging;
//    logging.trace("This is a trace logg", 1000);
//    logging.debug("This is a debug logg", 0);
//    logging.info("This is a info logg", 1);
//    logging.warn("This is a warn logg", 10);
//    logging.error("This is a error logg", 100);
//    logging.fatal("This is a fatal logg", 0);
}

TEST(Logger, printWithArgs) {
    Logger logging;
//    logging.trace("This is a trace logg %d", 1000, 12);
//    logging.debug("This is a debug logg %f", 0, 13);
//    logging.info("This is a info logg %s", 1, "1");
//    logging.warn("This is a warn logg %d", 10, 3);
//    logging.error("This is a error logg %d", 100, 1);
//    logging.fatal("This is a fatal logg %d", 0, 19);
}


TEST(Logger, logSaveToFile) {
    makeLogger("Logger_test");
    LOG_TRACE("salam");
//    Logger instance = Logger::getInstance(__FILE_NAME__);
//    instance.log(LogEntry(LogEntry::TRACE, __LINE__), "salam");
}