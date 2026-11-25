#define UNIT_TEST
#include <gtest/gtest.h>
#include "10-2-A.c++"


TEST(LabA, CmpOrdersByCourseThenSurname) {
    Student ivan{"Ivanenko", 1, CS, 5, 5, 5};
    Student petr{"Petrenko", 1, CS, 5, 5, 5};
    Student course2{"Ivanenko", 2, CS, 5, 5, 5};

    EXPECT_EQ(compare(ivan, petr, false), -1);   
    EXPECT_EQ(compare(ivan, petr, true), 1);     
    EXPECT_EQ(compare(ivan, course2, false), -1);
}
