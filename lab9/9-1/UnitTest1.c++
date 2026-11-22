#include <gtest/gtest.h>
#include <cmath>
#include "sum.h"
#include "var.h"
using namespace nsVar;

TEST(Sum, ZeroX) {
    x = 0; e = 1e-6;
    nsSum::sum();
    EXPECT_DOUBLE_EQ(s, 1.0);
}

TEST(Sum, HandCalculated) {      // 1 - 1 + 1/2 - 1/6 + 1/24 = 3/8
    x = 1; e = 0.1;
    nsSum::sum();
    EXPECT_NEAR(s, 0.375, 1e-12);
    EXPECT_EQ(n, 4);
}

TEST(Sum, MatchesExp) {
    x = 1; e = 1e-6;
    nsSum::sum();
    EXPECT_NEAR(s, std::exp(-1.0), e);
}