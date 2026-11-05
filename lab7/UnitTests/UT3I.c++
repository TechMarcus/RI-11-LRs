#define UNIT_TEST
#include "../lab6-3-i.c++"
#include <gtest/gtest.h>

TEST(FindBiggestEvenIterative, AllOddReturnsMinusOne)
{
    const int a[] = {1, 3, 5, -7, 9};
    bool found;
    EXPECT_EQ(false, FindBiggestEven(a, 5, &found));
}