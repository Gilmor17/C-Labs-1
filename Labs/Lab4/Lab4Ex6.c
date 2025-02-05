#include <stdio.h>
#include <math.h>

// Function to apply ceil (round up) using math.h
void applyCeilUsingMath(double *x) {
    *x = ceil(*x);  // Round up using math.h
}

// Function to apply floor (round down) using math.h
void applyFloorUsingMath(double *x) {
    *x = floor(*x);  // Round down using math.h
}

// Function to apply ceil manually (without math.h)
void applyCeilManually(double *x) {
    int intPart = (int)(*x);  // Truncate decimal part
    if (*x > intPart) {
        *x = intPart + 1;  // If x has a decimal part, round up
    } else {
        *x = intPart;  // If already an integer, no change
    }
}

// Function to apply floor manually (without math.h)
void applyFloorManually(double *x) {
    *x = (int)(*x); // Truncate decimal part to round down
}

int main() {
    double x;

    // Accept input from user
    printf("Enter a real number: ");
    scanf("%lf", &x);

    // Using math.h functions
    double x1 = x, x2 = x;
    applyCeilUsingMath(&x1);
    applyFloorUsingMath(&x2);

    printf("\nUsing math.h functions:\n");
    printf("Ceil of %.2f: %.2f\n", x, x1);
    printf("Floor of %.2f: %.2f\n", x, x2);

    // Using manual implementations
    double x3 = x, x4 = x;
    applyCeilManually(&x3);
    applyFloorManually(&x4);

    printf("\nUsing manual implementation:\n");
    printf("Ceil of %.2f: %.2f\n", x, x3);
    printf("Floor of %.2f: %.2f\n", x, x4);

    return 0;
}
