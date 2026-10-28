#define UNIT_TEST
#include "../lab6-3-i.c++"
#include <gtest/gtest.h>

TEST(FindBiggestEvenIterative, AllOddReturnsMinusOne)
{
    const int a[] = {1, 3, 5, -7, 9};
    EXPECT_EQ(-1, FindBiggestEven(a, 5));
}