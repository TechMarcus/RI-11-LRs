// chcp 65001 


#define UNIT_TEST
#include <gtest/gtest.h>
#include "./lab7-1.c++"

TEST(SwapPositionTest, SwapsTwoRows)
{
    const int rowCount = 2;
    const int colCount = 3;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    int row0[] = { 1, 2, 3 };
    int row1[] = { 4, 5, 6 };
    for (int j = 0; j < colCount; j++)
    {
        a[0][j] = row0[j];
        a[1][j] = row1[j];
    }

    SwapPosition(a, 0, 1, colCount);

    for (int j = 0; j < colCount; j++)
    {
        EXPECT_EQ(a[0][j], row1[j]);
        EXPECT_EQ(a[1][j], row0[j]);
    }

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
}