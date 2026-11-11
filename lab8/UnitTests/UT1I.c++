#define UNIT_TEST
#include "../lab8-1-i.c++"
#include <gtest/gtest.h>

TEST(IsSignTest, PlusIsSign)
{
    EXPECT_TRUE(IsSign('+'));
}

TEST(IsSignTest, MinusIsSign)
{
    EXPECT_TRUE(IsSign('-'));
}