#define UNIT_TEST
#include "../lab5-3.c++"
#include <gtest/gtest.h>

TEST(SFunctionTest, ZeroInput)
{
    EXPECT_DOUBLE_EQ(s(0.0), 2.0);
}

TEST(SFunctionTest, InputGreaterThanOrEqualToOne)
{
    EXPECT_NEAR(s(1.0), 0.4752732289200504, 1e-12);
}

TEST(SFunctionTest, NegativeInputLessThanOrEqualToMinusOne)
{
    EXPECT_NEAR(s(-2.0), 8.668679456761282, 1e-12);
}

TEST(SFunctionTest, PositiveInputBetweenZeroAndOne)
{
    EXPECT_NEAR(s(0.5), 1.3966033168673397, 1e-12);
}

TEST(SFunctionTest, NegativeInputBetweenMinusOneAndZero)
{
    EXPECT_NEAR(s(-0.5), 1.3966033168673397, 1e-12);
}