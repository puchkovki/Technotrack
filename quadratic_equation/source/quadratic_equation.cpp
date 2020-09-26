// Copyright 2020 Puchkov Kyryll Technotrack
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve_equation.hpp"

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! @brief Entry point
//!
//! Execution of the program
//! starts here.
//!
//! @return Program exit status
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
int main(void) {
    // Coefficients of the equation
    double a = NAN;
    double b = NAN;
    double c = NAN;
    // Checking whether reading is correct
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Cannot read numbers\n");
        return EXIT_FAILURE;
    }

    double r1 = NAN;
    double r2 = NAN;
    AmountOfRoots roots = solveEquation(a, b, c, &r1, &r2);

    switch (roots) {
        case NO_ROOT:
            printf("Equation has no rots!\n");
            break;

        case ONE_ROOT:
            printf("The only root is %lf\n", r1);
            break;

        case TWO_ROOTS:
            printf("Roots are %lf and %lf\n", r1, r2);
            break;

        case INFINITE_ROOTS:
            printf("There are infinite amount of roots\n");
            break;

        default:
            printf("An error occured!\n");
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
