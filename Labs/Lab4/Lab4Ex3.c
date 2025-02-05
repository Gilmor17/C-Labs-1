#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Iterative GCD function using Euclid's algorithm
long gcd_iterative(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

// Recursive GCD function using Euclid's algorithm
long gcd_recursive(int x, int y) {
    if (y == 0) {
        return x;
    }
    return gcd_recursive(y, x % y);
}

// Function to test the performance (time and stack usage) of each GCD function
void test_gcd(int x, int y) {
    clock_t start, end;
    double time_taken;

    // Test iterative GCD
    start = clock();
    long iterative_result = gcd_iterative(x, y);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Iterative GCD of (%d, %d) is %ld, Time taken: %f seconds\n", x, y, iterative_result, time_taken);

    // Test recursive GCD
    start = clock();
    long recursive_result = gcd_recursive(x, y);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Recursive GCD of (%d, %d) is %ld, Time taken: %f seconds\n", x, y, recursive_result, time_taken);
}

int main() {
    int x, y;

    // User input for the numbers
    printf("Enter two numbers (x > y) to calculate the GCD: ");
    scanf("%d %d", &x, &y);

    // Ensure x > y as per the problem statement
    if (x <= y) {
        printf("Invalid input. Ensure that x > y.\n");
        return 1;
    }

    // Testing GCD functions
    test_gcd(x, y);

    return 0;
}
