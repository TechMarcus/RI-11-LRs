#define UNIT_TEST
#include "../lab6-2-i.c++"
#include <gtest/gtest.h>

TEST(FindIndexOfSmallestElementTest, FindsSmallestElementInUnsortedArray) {
    int a[] = {5, 2, 8, 1, 9};

    EXPECT_EQ(3, FindIndexOfSmallestElement(a, 5));
}

TEST(FindIndexOfSmallestElementTest, FindsSmallestElementAtEnd) {
    int a[] = {5, 8, 3, 1};

    EXPECT_EQ(3, FindIndexOfSmallestElement(a, 4));
}