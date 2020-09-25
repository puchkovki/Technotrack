// Copyright 2020 Puchkov Kyryll Technotrack
#ifndef TECHNOTRACK_QUADRATIC_EQUATION_INCLUDE_SOLVE_EQUATION_H_
#define TECHNOTRACK_QUADRATIC_EQUATION_INCLUDE_SOLVE_EQUATION_H_

#include <stdio.h>
#include <stdlib.h>
typedef enum AmountOfRoots {
    NO_ROOT,
    ONE_ROOT,
    TWO_ROOTS,
    INFINITE_ROOTS,
    MISTAKE
} AmountOfRoots;

// Solving the quadratic equation through the discriminant
// Output — number of roots; -1 if the there an infinite roots
AmountOfRoots solveEquation(const double a, const double b,
        const double c, double *r1, double *r2);

#endif  // TECHNOTRACK_QUADRATIC_EQUATION_INCLUDE_SOLVE_EQUATION_H_
