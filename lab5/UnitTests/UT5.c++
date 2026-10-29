#define UNIT_TEST
#include "../lab5-5.c++"
#include <gtest/gtest.h>

TEST(FTest, BasicCases) {
    EXPECT_EQ(f(0, 0), 0);
    EXPECT_EQ(f(1, 0), 1);
    EXPECT_EQ(f(3, 0), 2);
    EXPECT_EQ(f(7, 0), 3);
    EXPECT_EQ(f(15, 0), 4);
    EXPECT_EQ(f(255, 0), 8);
}