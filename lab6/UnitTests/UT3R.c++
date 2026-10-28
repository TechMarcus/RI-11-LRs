#define UNIT_TEST
#include "../lab6-3-r.c++"
#include <gtest/gtest.h>


TEST(FindBiggestEvenRecursive, MixedPositiveNumbers)
{
    const int a[] = {1, 4, 7, 10, 3, 8};
    EXPECT_EQ(10, FindBiggestEven(a, 6));
}