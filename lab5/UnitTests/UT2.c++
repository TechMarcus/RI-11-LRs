#define UNIT_TEST
#include "../lab5-2.c++"

#include <gtest/gtest.h>

TEST(AFunctionTest, PositiveInputs)
{
    EXPECT_DOUBLE_EQ(A(2.0, 2, 3.0), -3.0);
}

TEST(AFunctionTest, NegativeX)
{
    EXPECT_DOUBLE_EQ(A(-4.0, 2, 3.0), 6.0);
}

TEST(AFunctionTest, FractionalResult)
{
    EXPECT_DOUBLE_EQ(A(1.0, 2, 4.0), -2.0);
}

TEST(AFunctionTest, ZeroA)
{
    EXPECT_DOUBLE_EQ(A(5.0, 2, 0.0), 0.0);
}

TEST(AFunctionTest, ZeroX)
{
    EXPECT_DOUBLE_EQ(A(0.0, 2, 3.0), 0.0);
}