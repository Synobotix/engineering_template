#include "core/ILogger.hpp"
#include "mocks/MockLogger.hpp"
#include <gtest/gtest.h>
#include <string>

using core::LogSeverity;
using test::MockLogger;

TEST(LogStream, FlushesOnDestruction)
{
    MockLogger logger;
    {
        auto s = logger.info();
        s << "hello";
    } // destructor flushes here
    ASSERT_EQ(logger.entries().size(), 1u);
    EXPECT_EQ(logger.entries()[0].message, "hello");
    EXPECT_EQ(logger.entries()[0].severity, LogSeverity::kInfo);
}

TEST(LogStream, NoFlushWhenEmpty)
{
    MockLogger logger;
    {
        auto s = logger.debug(); // nothing written
    }
    EXPECT_TRUE(logger.entries().empty());
}

TEST(LogStream, ChainedAppend)
{
    MockLogger logger;
    { logger.info() << "a" << "b" << "c"; }
    ASSERT_EQ(logger.entries().size(), 1u);
    EXPECT_EQ(logger.entries()[0].message, "abc");
}

TEST(LogStream, IntegerFormatting)
{
    MockLogger logger;
    { logger.info() << int32_t{-7} << " " << uint32_t{42u}; }
    EXPECT_EQ(logger.entries()[0].message, "-7 42");
}

TEST(LogStream, BoolFormatting)
{
    MockLogger logger;
    { logger.debug() << true << " " << false; }
    EXPECT_EQ(logger.entries()[0].message, "true false");
}

TEST(LogStream, FloatFormatting)
{
    MockLogger logger;
    { logger.info() << 1.5f; }
    EXPECT_FALSE(logger.entries()[0].message.empty());
}

TEST(LogStream, SeverityFactories)
{
    MockLogger logger;
    { logger.debug()   << "d"; }
    { logger.verbose() << "v"; }
    { logger.info()    << "i"; }
    { logger.warning() << "w"; }
    { logger.error()   << "e"; }

    ASSERT_EQ(logger.entries().size(), 5u);
    EXPECT_EQ(logger.entries()[0].severity, LogSeverity::kDebug);
    EXPECT_EQ(logger.entries()[1].severity, LogSeverity::kVerbose);
    EXPECT_EQ(logger.entries()[2].severity, LogSeverity::kInfo);
    EXPECT_EQ(logger.entries()[3].severity, LogSeverity::kWarning);
    EXPECT_EQ(logger.entries()[4].severity, LogSeverity::kError);
}

TEST(LogStream, BufferTruncatesAt256)
{
    MockLogger logger;
    {
        auto s = logger.info();
        for (int i = 0; i < 300; ++i) s << 'x';
    }
    ASSERT_EQ(logger.entries().size(), 1u);
    EXPECT_EQ(logger.entries()[0].message.size(), 256u);
}
