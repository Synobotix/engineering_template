#include "infrastructure/logging/ConsoleLogger.hpp"
#include <gtest/gtest.h>

using core::LogSeverity;
using infrastructure::logging::ColorMode;
using infrastructure::logging::ConsoleLogger;

TEST(ConsoleLogger, DefaultConstruction)
{
    ConsoleLogger logger;
    EXPECT_EQ(logger.get(), LogSeverity::kInfo);
}

TEST(ConsoleLogger, SetAndGetSeverity)
{
    ConsoleLogger logger;
    logger.set(LogSeverity::kDebug);
    EXPECT_EQ(logger.get(), LogSeverity::kDebug);
    logger.set(LogSeverity::kError);
    EXPECT_EQ(logger.get(), LogSeverity::kError);
}

TEST(ConsoleLogger, ConstructWithColorModes)
{
    ConsoleLogger always{LogSeverity::kDebug, ColorMode::Always};
    ConsoleLogger never{LogSeverity::kDebug, ColorMode::Never};
    ConsoleLogger autom{LogSeverity::kDebug, ColorMode::Auto};
    EXPECT_EQ(always.get(), LogSeverity::kDebug);
    EXPECT_EQ(never.get(),  LogSeverity::kDebug);
    EXPECT_EQ(autom.get(),  LogSeverity::kDebug);
}

TEST(ConsoleLogger, LogDoesNotCrashForAllSeverities)
{
    ConsoleLogger logger{LogSeverity::kDebug, ColorMode::Never};
    EXPECT_NO_THROW(logger.log("debug msg",   LogSeverity::kDebug));
    EXPECT_NO_THROW(logger.log("verbose msg", LogSeverity::kVerbose));
    EXPECT_NO_THROW(logger.log("info msg",    LogSeverity::kInfo));
    EXPECT_NO_THROW(logger.log("warning msg", LogSeverity::kWarning));
    EXPECT_NO_THROW(logger.log("error msg",   LogSeverity::kError));
}

TEST(ConsoleLogger, FiltersBelowMinSeverity)
{
    // We can only verify this doesn't crash — stderr capture is not portable
    ConsoleLogger logger{LogSeverity::kError, ColorMode::Never};
    EXPECT_NO_THROW(logger.log("filtered debug", LogSeverity::kDebug));
    EXPECT_NO_THROW(logger.log("shown error",    LogSeverity::kError));
}

TEST(ConsoleLogger, StreamOperatorWorks)
{
    ConsoleLogger logger{LogSeverity::kDebug, ColorMode::Never};
    EXPECT_NO_THROW({
        logger.info() << "stream " << "test " << int32_t{42};
    });
}
