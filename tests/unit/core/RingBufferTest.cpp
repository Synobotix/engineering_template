#include "core/RingBuffer.hpp"
#include <gtest/gtest.h>

using core::RingBuffer;

TEST(RingBuffer, StartsEmpty)
{
    RingBuffer<int, 4> buf;
    EXPECT_TRUE(buf.is_empty());
    EXPECT_FALSE(buf.is_full());
    EXPECT_EQ(buf.size(), 0u);
    EXPECT_EQ(buf.capacity(), 4u);
}

TEST(RingBuffer, PushAndPop)
{
    RingBuffer<int, 4> buf;
    EXPECT_TRUE(buf.push(10));
    EXPECT_TRUE(buf.push(20));
    EXPECT_EQ(buf.size(), 2u);

    int v = 0;
    EXPECT_TRUE(buf.pop(v));
    EXPECT_EQ(v, 10);
    EXPECT_TRUE(buf.pop(v));
    EXPECT_EQ(v, 20);
    EXPECT_TRUE(buf.is_empty());
}

TEST(RingBuffer, FullRejectsPush)
{
    RingBuffer<int, 2> buf;
    EXPECT_TRUE(buf.push(1));
    EXPECT_TRUE(buf.push(2));
    EXPECT_TRUE(buf.is_full());
    EXPECT_FALSE(buf.push(3));
}

TEST(RingBuffer, PopOnEmptyReturnsFalse)
{
    RingBuffer<int, 4> buf;
    int v = 0;
    EXPECT_FALSE(buf.pop(v));
}

TEST(RingBuffer, Peek)
{
    RingBuffer<int, 4> buf;
    EXPECT_TRUE(buf.push(7));
    int v = 0;
    EXPECT_TRUE(buf.peek(v));
    EXPECT_EQ(v, 7);
    EXPECT_EQ(buf.size(), 1u); // peek does not consume
}

TEST(RingBuffer, WrapAround)
{
    RingBuffer<int, 3> buf;
    EXPECT_TRUE(buf.push(1));
    EXPECT_TRUE(buf.push(2));
    EXPECT_TRUE(buf.push(3));
    int v = 0;
    EXPECT_TRUE(buf.pop(v)); // consume 1, head wraps
    EXPECT_TRUE(buf.push(4));
    EXPECT_TRUE(buf.pop(v)); EXPECT_EQ(v, 2);
    EXPECT_TRUE(buf.pop(v)); EXPECT_EQ(v, 3);
    EXPECT_TRUE(buf.pop(v)); EXPECT_EQ(v, 4);
    EXPECT_TRUE(buf.is_empty());
}

TEST(RingBuffer, Clear)
{
    RingBuffer<int, 4> buf;
    EXPECT_TRUE(buf.push(1));
    EXPECT_TRUE(buf.push(2));
    buf.clear();
    EXPECT_TRUE(buf.is_empty());
    EXPECT_EQ(buf.size(), 0u);
}
