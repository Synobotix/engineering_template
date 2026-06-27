#include "core/Result.hpp"
#include <gtest/gtest.h>
#include <string>

using core::Result;

TEST(Result, OkHoldsValue)
{
    auto r = Result<int, std::string>::ok(42);
    EXPECT_TRUE(r.is_ok());
    EXPECT_FALSE(r.is_err());
    EXPECT_EQ(r.value(), 42);
}

TEST(Result, ErrHoldsError)
{
    auto r = Result<int, std::string>::err("fail");
    EXPECT_FALSE(r.is_ok());
    EXPECT_TRUE(r.is_err());
    EXPECT_EQ(r.error(), "fail");
}

TEST(Result, MutableValueAccess)
{
    auto r = Result<int, std::string>::ok(1);
    r.value() = 99;
    EXPECT_EQ(r.value(), 99);
}

TEST(Result, MutableErrorAccess)
{
    auto r = Result<int, std::string>::err(std::string("bad"));
    r.error() += "!";
    EXPECT_EQ(r.error(), "bad!");
}

TEST(Result, OkWithMoveOnlyType)
{
    auto r = Result<std::string, int>::ok("hello");
    EXPECT_TRUE(r.is_ok());
    EXPECT_EQ(r.value(), "hello");
}
