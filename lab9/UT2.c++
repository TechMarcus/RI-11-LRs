#define UNIT_TEST
#include <gtest/gtest.h>
#include "9-2.c++"

TEST(MaxMacro, ReturnsLarger) {
    EXPECT_EQ(MAX(3, 7), 7);
    EXPECT_EQ(MAX(-2, -5), -2);
}