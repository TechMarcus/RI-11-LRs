#define UNIT_TEST
#include "../lab6-4-r.c++"
#include <gtest/gtest.h>


TEST(SumPositiveTest, Basic)
{
    int a[] = { -3, 5, 0, 2, -1 };

    EXPECT_EQ(SumPositive(a, 5), 7);
}