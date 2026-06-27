#include "application/AppRunner.hpp"
#include "mocks/MockLifecycle.hpp"
#include "mocks/MockLogger.hpp"
#include <gtest/gtest.h>

using test::MockLifecycle;
using test::MockLogger;

TEST(AppRunnerE2E, SuccessfulRunReturnsZero)
{
    MockLifecycle lifecycle{/*start_ok=*/true, /*ticks=*/0};
    MockLogger    logger;

    application::AppRunner runner{lifecycle, logger};
    EXPECT_EQ(runner.run(), 0);
}

TEST(AppRunnerE2E, LifecycleStartCalledOnRun)
{
    MockLifecycle lifecycle;
    MockLogger    logger;

    application::AppRunner runner{lifecycle, logger};
    runner.run();

    EXPECT_TRUE(lifecycle.started());
}

TEST(AppRunnerE2E, LifecycleStopCalledAfterLoop)
{
    MockLifecycle lifecycle{true, 0};
    MockLogger    logger;

    application::AppRunner runner{lifecycle, logger};
    runner.run();

    EXPECT_TRUE(lifecycle.stopped());
}

TEST(AppRunnerE2E, FailedStartReturnsOne)
{
    MockLifecycle lifecycle{/*start_ok=*/false};
    MockLogger    logger;

    application::AppRunner runner{lifecycle, logger};
    EXPECT_EQ(runner.run(), 1);
}

TEST(AppRunnerE2E, FailedStartDoesNotCallStop)
{
    MockLifecycle lifecycle{false};
    MockLogger    logger;

    application::AppRunner runner{lifecycle, logger};
    runner.run();

    EXPECT_FALSE(lifecycle.stopped());
}

TEST(AppRunnerE2E, BuildInfoLoggedAtStartup)
{
    MockLifecycle lifecycle;
    MockLogger    logger;

    application::AppRunner runner{lifecycle, logger};
    runner.run();

    EXPECT_FALSE(logger.entries().empty());
    // First log entry should contain the project name
    EXPECT_NE(logger.entries()[0].message.find("engineering_template"), std::string::npos);
}

TEST(AppRunnerE2E, ErrorLoggedOnFailedStart)
{
    MockLifecycle lifecycle{false};
    MockLogger    logger;

    application::AppRunner runner{lifecycle, logger};
    runner.run();

    EXPECT_TRUE(logger.has(core::LogSeverity::kError, "lifecycle"));
}

TEST(AppRunnerE2E, RunsLoopForNTicks)
{
    MockLifecycle lifecycle{true, 3}; // loop runs 3 times
    MockLogger    logger;

    application::AppRunner runner{lifecycle, logger};
    EXPECT_EQ(runner.run(), 0);
    EXPECT_TRUE(lifecycle.stopped());
}
