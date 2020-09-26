// Copyright 2020 Puchkov Kyryll Technotrack
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "solve_equation.hpp"

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Solves a square equation a*x^2 + b*x + c = 0
//!
//! @param [in] a a‐coefficient
//! @param [in] b b‐coefficient
//! @param [in] c c‐coefficient
//! @param [out] r1 Pointer to the 1st root
//! @param [out] r2 Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots,
//! returns INFINITE_ROOTS.
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
// Solving the quadratic equation through the discriminant
// Output — number of roots; -1 if the there an infinite roots
AmountOfRoots solveEquation(const double a, const double b,
        const double c, double *r1, double *r2) {
    // Checking the validity of input in function solveEquation
    // Are the coefficients are valid (not infinity nor NaN)
    assert(finite(a));
    assert(finite(b));
    assert(finite(c));

    // Are the pointers to the root valid (!= 0)
    assert(r1 != NULL);
    assert(r2 != NULL);

    if (a == 0.0) {
        if (b == 0.0) {
            if (c == 0.0) {  // 0 == 0, infinite roots
                return INFINITE_ROOTS;
            }

            // nonzero number != 0, always false
            return NO_ROOT;
        }

        // b * x = c
        *r1 = -c / b;
        return ONE_ROOT;
    }

    // a != 0
    double D2 = b * b - 4 * a * c;

    if (D2 >= 0) {
        if (D2 > 0) {
            *r1 = (-b - sqrt(D2)) / (2 * a);
            *r2 = (-b + sqrt(D2)) / (2 * a);
            return TWO_ROOTS;
        }

        // D2 == 0
        *r1 = -b / 2 / a;
        return ONE_ROOT;
    }

    // D2 <= 0
    return NO_ROOT;
}
