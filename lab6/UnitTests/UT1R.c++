#define UNIT_TEST
#include "../lab6-1-r.c++"
#include <gtest/gtest.h>

TEST(IsValidKriteriaTest, ReturnsTrueForPositiveNumber) {
    EXPECT_TRUE(IsValidKriteria(5));
}

TEST(IsValidKriteriaTest, ReturnsTrueForPositiveMultipleOfThree) {
    EXPECT_TRUE(IsValidKriteria(9));
}

TEST(IsValidKriteriaTest, ReturnsFalseForZero) {
    EXPECT_FALSE(IsValidKriteria(0));
}