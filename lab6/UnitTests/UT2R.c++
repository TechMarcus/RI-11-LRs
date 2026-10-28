#define UNIT_TEST
#include "../lab6-2-r.c++"
#include <gtest/gtest.h>


TEST(FindIndexOfSmallestElementTest, FindsSmallestElementInUnsortedArray) {
    int a[] = {5, 2, 8, 1, 9};

    EXPECT_EQ(3, FindIndexOfSmallestElement(a, 5, 0, 0));
}