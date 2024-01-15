#include "LogEntry.h"
#include "Logger.h"
#include <cstring>
#include <gtest/gtest.h>

TEST(Logger, justPrintTypesOfLogger) {
    Logger logging;
    logging.log(LogEntry(LogEntry::TRACE, __LINE__), "Hello");
    logging.log(LogEntry(LogEntry::DEBUG, __LINE__), "Hello");
    logging.log(LogEntry(LogEntry::INFO, __LINE__), "Hello");
    logging.log(LogEntry(LogEntry::WARN, __LINE__), "Hello");
    logging.log(LogEntry(LogEntry::ERROR, __LINE__), "Hello");
    logging.log(LogEntry(LogEntry::FATAL, __LINE__), "Hello");
}

TEST(Logger, printWithArgs) {
    Logger logging;
    logging.log(LogEntry(LogEntry::TRACE, __LINE__), "Hello %d", 12);
    logging.log(LogEntry(LogEntry::DEBUG, __LINE__), "Hello %d", 12);
    logging.log(LogEntry(LogEntry::INFO, __LINE__), "Hello %d", 12);
    logging.log(LogEntry(LogEntry::WARN, __LINE__), "Hello %d", 12);
    logging.log(LogEntry(LogEntry::ERROR, __LINE__), "Hello %d", 12);
    logging.log(LogEntry(LogEntry::FATAL, __LINE__), "Hello %d", 12);
}

TEST(Logger, printWithMacro) {
    Logger logging("logger_test");
    logging.log(
        Info,
        "sadfsaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasdfsdfsdfsdf"
        "sfd %d",
        14);
    /* log_debug("salam %d", 11); */
    /* log_info("salam %d", 12); */
    /* log_warn("salam %d", 13); */
    /* log_error("salam %d", 14); */
    /* log_fatal("salam %d", 15); */

    /* log_trace("salam %d", 10); */
    /* log_debug("salam %d", 11); */
    /* log_info("salam %d", 12); */
    /* log_warn("salam %d", 13); */
    /* LOG_ERROR("salam %d", 14); */
    /* LOG_FATAL("salam %d", 15); */
}
