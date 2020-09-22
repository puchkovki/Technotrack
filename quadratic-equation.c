#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

// Solving the quadratic equation through the discriminant
// Output — number of roots; -1 if the there an infinite roots 
int solveEquation (const double a, const double b,
        const double c, double *r1, double *r2);


// Checking the validity of input in function solveEquation 
void correctInput (const double a, const double b,
        const double c, double *r1, double *r2);

int main (void) {
    // Coefficients of the equation
    double a = 0.0, b = 0.0, c = 0.0;
    // Checking whether reading is correct
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Cannot read numbers\n");
        return EXIT_FAILURE;
    }

    double r1 = 0, r2 = 0;
    correctInput(a, b, c, &r1, &r2);
    int roots = solveEquation(a, b, c, &r1, &r2);

    switch (roots) {
        case 0: 
            printf("Equation has no rots!\n");
            break;

        case 1:
            printf("The only root is %lf\n", r1);
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

// Solving the quadratic equation through the discriminant
// Output — number of roots; -1 if the there an infinite roots 
int solveEquation (const double a, const double b,
        const double c, double *r1, double *r2) {

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

// Checking the validity of input in function solveEquation 
void correctInput (const double a, const double b,
        const double c, double *r1, double *r2) {
    // Are the coefficients are valid (not infinity nor NaN)
    assert(finite(a));
    assert(finite(b));
    assert(finite(c));

    // Are the pointers to the root valid (!= 0)
    assert(r1 != NULL);
    assert(r2 != NULL);
}