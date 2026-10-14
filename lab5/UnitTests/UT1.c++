#define UNIT_TEST
#include "../lab5-1.c++"
#include <gtest/gtest.h>

TEST(KFunctionTest, PositiveInputs)
{
    EXPECT_DOUBLE_EQ(k(1.0, 1.0), 1.0);
}

TEST(KFunctionTest, NegativeX)
{
    EXPECT_NEAR(k(-1.0, 2.0), 13.0 / 7.0, 1e-9);
}

TEST(KFunctionTest, NegativeY)
{
    EXPECT_NEAR(k(2.0, -1.0), -5.0 / 7.0, 1e-9);
}