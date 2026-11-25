#define UNIT_TEST
#include <gtest/gtest.h>
#include "10-2-B.c++"


TEST(LabB, CmpOrdersBySpecialtyNameThenSurname) {
    Student inf{"Petrenko", 1, INF, 5, 5, {4}};
    Student cs{"Ivanenko", 1, CS, 5, 5, {4}};
    Student cs2{"Koval", 1, CS, 5, 5, {4}};

    EXPECT_EQ(compare(inf, cs, false), -1);   // "Інформатика" < "Комп'ютерні науки"
    EXPECT_EQ(compare(cs, cs2, true), 1);     // однакова спеціальність: прізвище за спаданням
}
