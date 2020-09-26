// Copyright 2020 Puchkov Kyryll Technotrack
#ifndef TECHNOTRACK_QUADRATIC_EQUATION_INCLUDE_SOLVE_EQUATION_HPP_
#define TECHNOTRACK_QUADRATIC_EQUATION_INCLUDE_SOLVE_EQUATION_HPP_

#include <stdio.h>
#include <stdlib.h>


//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! @brief Enum provides clear namig of a root amounts
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
typedef enum AmountOfRoots {
    NO_ROOT, /**< enum value 1 */
    ONE_ROOT, /**< enum value 2 */
    TWO_ROOTS, /**< enum value 3 */
    INFINITE_ROOTS, /**< enum value 4 */
    MISTAKE /**< enum value 5 */
} AmountOfRoots;

// Solving the quadratic equation through the discriminant
// Output — number of roots; -1 if the there an infinite roots
AmountOfRoots solveEquation(const double a, const double b,
        const double c, double *r1, double *r2);

#endif  // TECHNOTRACK_QUADRATIC_EQUATION_INCLUDE_SOLVE_EQUATION_HPP_
