#define UNIT_TEST
#include "../lab6-1-i.c++"
#include <gtest/gtest.h>

TEST(IsValidKriteriaTest, PositiveNumberReturnsTrue) {
    EXPECT_TRUE(IsValidKriteria(5));
}

TEST(IsValidKriteriaTest, ZeroReturnsFalse) {
    EXPECT_FALSE(IsValidKriteria(0));
}

TEST(IsValidKriteriaTest, NegativeMultipleOfThreeReturnsFalse) {
    EXPECT_FALSE(IsValidKriteria(-6));
}