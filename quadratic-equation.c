#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int solveEquation (const double a, const double b,
        const double c, double *r1, double *r2);

int main (void) {
    double a, b, c;
    
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Cannot read an integer\n");
        return EXIT_FAILURE;
    }

    double r1 = 0, r2 = 0;
    int roots = solveEquation(a, b, c, &r1, &r2);

    switch (roots) {
        case 0: 
            printf("Equation has no rots!\n");
            break;

        case 1:
            printf("The inly root is %lf\n", r1);
            break;

        case 2:
            printf("Roots are %lf and %lf\n", r1, r2);
            break;

        case -1:
            printf("There are infinite amount of roots\n");
            break;

        default:
            printf("An error occured!\n");
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Solves a square equation ax2 + bx + c = 0
//!
//! @param [in] a a‐coefficient
//! @param [in] b b‐coefficient
//! @param [in] c c‐coefficient
//! @param [out] x1 Pointer to the 1st root
//! @param [out] x2 Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots,
//! returns -1.
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
int solveEquation (const double a, const double b,
        const double c, double *r1, double *r2) {
    // Checking whether input is correct
    assert(finite(a));
    assert(finite(b));
    assert(finite(c));
    assert(r1 != NULL);
    assert(r2 != NULL);

    if (a == 0.0) {
        if (b == 0.0) {
            if (c == 0.0) {
                // 0 == 0, infinite roots
                return -1;
            } else { // nonzero number != 0, always false
                return 0;
            }
        } else { // b * x = c
            *r1 = -c / b;
            return 1;
        }
    } else { // a != 0
        double D2 = b * b - 4 * a * c;

        if (D2 >= 0) {
            if (D2 > 0) {
                *r1 = (-b - sqrt(D2)) / (2 * a);
                *r2 = (-b + sqrt(D2)) / (2 * a);
                return 2;
            } else { // D2 == 0
                *r1 = -b / 2 / a;
                return 1;
            }
        } else { // D2 <= 0
            return 0;
        }
    }
}
