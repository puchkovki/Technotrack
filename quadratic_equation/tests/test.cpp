// Copyright 2020 Puchkov Kyryll Technotrack
#include <math.h>
#include <gtest/gtest.h>
#include "solve_equation.hpp"

TEST(Quadratic, test_1) {
    double a = 1;
    double b = 2;
    double c = 0;

    double r1 = NAN;
    double r2 = NAN;
    AmountOfRoots roots = solveEquation(a, b, c, &r1, &r2);

    ASSERT_EQ(roots, TWO_ROOTS) << "Amount of roots is correct";
    ASSERT_DOUBLE_EQ(r1, -2.000000) << "First root is correct";
    ASSERT_DOUBLE_EQ(r2, 0.000000) << "Second root is correct";
}

TEST(Quadratic, test_2) {
    double a = 1;
    double b = 0;
    double c = 2;

    double r1 = NAN;
    double r2 = NAN;
    AmountOfRoots roots = solveEquation(a, b, c, &r1, &r2);

    ASSERT_EQ(roots, NO_ROOT) << "Amount of roots is correct";
    EXPECT_TRUE(isnan(r1));
    EXPECT_TRUE(isnan(r2));
}

TEST(Quadratic, test_3) {
    double a = 0;
    double b = 1;
    double c = 2;

    double r1 = NAN;
    double r2 = NAN;
    AmountOfRoots roots = solveEquation(a, b, c, &r1, &r2);

    ASSERT_EQ(roots, ONE_ROOT) << "Amount of roots is correct";
    ASSERT_DOUBLE_EQ(r1, -2.000000) << "First root is correct";
    EXPECT_TRUE(isnan(r2));
}

TEST(Quadratic, test_4) {
    double a = 0;
    double b = 0;
    double c = 0;

    double r1 = NAN;
    double r2 = NAN;
    AmountOfRoots roots = solveEquation(a, b, c, &r1, &r2);

    ASSERT_EQ(roots, INFINITE_ROOTS) << "Amount of roots is correct";
    EXPECT_TRUE(isnan(r1));
    EXPECT_TRUE(isnan(r2));
}
/*
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/
