#define UNIT_TEST
#include "../lab5-4.c++"
#include <gtest/gtest.h>

static double ExpectedSum(int limit, int N) {
    double sum = 0.0;

    for (int k = N; k <= limit; ++k) {
        sum += std::sqrt(
            std::sin(1.0 * k) * std::sin(1.0 * k) +
            std::cos(N / k) * std::cos(N / k)
        );
    }

    return sum;
}

class SumFunctionsTest : public ::testing::Test {
protected:
    void CheckAllFunctions(int limit, int N) {
        const double expected = ExpectedSum(limit, N);

        EXPECT_NEAR(S0(limit, N), expected, 1e-9);
        EXPECT_NEAR(S1(limit, N, N), expected, 1e-9);
        EXPECT_NEAR(S2(limit, N, limit), expected, 1e-9);
        EXPECT_NEAR(S3(limit, N, N, 0.0), expected, 1e-9);
        EXPECT_NEAR(S4(limit, N, limit, 0.0), expected, 1e-9);
    }
};

TEST_F(SumFunctionsTest, NormalRange) {
    CheckAllFunctions(10, 2);
}

TEST_F(SumFunctionsTest, LargerRange) {
    CheckAllFunctions(100, 5);
}

TEST_F(SumFunctionsTest, SmallRange) {
    CheckAllFunctions(5, 1);
}

TEST_F(SumFunctionsTest, SingleElementRange) {
    CheckAllFunctions(5, 5);
}

TEST_F(SumFunctionsTest, NonZeroInitialAccumulator) {
    const int limit = 10;
    const int N = 3;
    const double initial = 7.5;
    const double expected = initial + ExpectedSum(limit, N);

    EXPECT_NEAR(S3(limit, N, N, initial), expected, 1e-9);
    EXPECT_NEAR(S4(limit, N, limit, initial), expected, 1e-9);
}

TEST(SumFunctionsBoundaryTest, S1StartingIndexExceedsLimit) {
    EXPECT_DOUBLE_EQ(S1(5, 2, 6), 0.0);
}

TEST(SumFunctionsBoundaryTest, S2StartingIndexBelowN) {
    EXPECT_DOUBLE_EQ(S2(10, 5, 4), 0.0);
}

TEST(SumFunctionsBoundaryTest, EmptyRangeForS0AndS1) {
    EXPECT_DOUBLE_EQ(S0(3, 5), 0.0);
    EXPECT_DOUBLE_EQ(S1(3, 5, 5), 0.0);
}

TEST(SumFunctionsBoundaryTest, EmptyRangeForS2) {
    EXPECT_DOUBLE_EQ(S2(3, 5, 3), 0.0);
}