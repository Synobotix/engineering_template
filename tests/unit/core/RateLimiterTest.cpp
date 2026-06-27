#include "core/RateLimiter.hpp"
#include "mocks/MockClock.hpp"
#include <gtest/gtest.h>

using core::RateLimiter;
using test::MockClock;

TEST(RateLimiter, AllowsUpToBurstImmediately)
{
    MockClock clock{0};
    RateLimiter<10, 3> limiter{clock}; // 10 Hz, burst=3

    EXPECT_TRUE(limiter.allow());
    EXPECT_TRUE(limiter.allow());
    EXPECT_TRUE(limiter.allow());
    EXPECT_FALSE(limiter.allow()); // bucket empty
}

TEST(RateLimiter, RefillsOverTime)
{
    MockClock clock{0};
    RateLimiter<10, 1> limiter{clock}; // 10 Hz, burst=1

    EXPECT_TRUE(limiter.allow()); // consume the 1 token
    EXPECT_FALSE(limiter.allow());

    clock.advance(100); // 100ms = 1 token at 10Hz
    EXPECT_TRUE(limiter.allow());
    EXPECT_FALSE(limiter.allow()); // depleted again
}

TEST(RateLimiter, DoesNotExceedBurstOnRefill)
{
    MockClock clock{0};
    RateLimiter<10, 2> limiter{clock}; // burst cap = 2

    EXPECT_TRUE(limiter.allow()); // consume 1
    clock.advance(10000); // would earn 100 tokens — capped at burst=2
    EXPECT_EQ(limiter.available_tokens(), 1u); // 1 remaining + refill up to burst
    EXPECT_TRUE(limiter.allow());
    EXPECT_TRUE(limiter.allow());
    EXPECT_FALSE(limiter.allow());
}

TEST(RateLimiter, AvailableTokensReflectsState)
{
    MockClock clock{0};
    RateLimiter<5, 5> limiter{clock};
    EXPECT_EQ(limiter.available_tokens(), 5u);
    EXPECT_TRUE(limiter.allow());
    EXPECT_EQ(limiter.available_tokens(), 4u);
}
