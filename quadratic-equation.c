#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

typedef enum AmountOfRoots {
    NO_ROOT,
    ONE_ROOT,
    TWO_ROOTS,
    INFINITE_ROOTS,
    MISTAKE
} AmountOfRoots;

// Solving the quadratic equation through the discriminant
// Output — number of roots; -1 if the there an infinite roots 
AmountOfRoots solveEquation (const double a, const double b,
        const double c, double *r1, double *r2);

int main (void) {
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
    int roots = solveEquation(a, b, c, &r1, &r2);

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

// Solving the quadratic equation through the discriminant
// Output — number of roots; -1 if the there an infinite roots 
AmountOfRoots solveEquation (const double a, const double b,
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
            if (c == 0.0) { // 0 == 0, infinite roots
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