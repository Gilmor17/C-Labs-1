#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Iterative factorial function
long fact(int n) {
    long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }
    return ans;
}

// Recursive factorial function
long rfact(int n) {
    if (n <= 1)
        return 1;
    else
        return n * rfact(n - 1);
}

// Function to test the performance (time and stack usage) of each factorial function
void test_factorial(int n) {
    clock_t start, end;
    double time_taken;

    // Test iterative factorial
    start = clock();
    long iterative_result = fact(n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Iterative factorial of %d is %ld, Time taken: %f seconds\n", n, iterative_result, time_taken);

    // Test recursive factorial
    start = clock();
    long recursive_result = rfact(n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Recursive factorial of %d is %ld, Time taken: %f seconds\n", n, recursive_result, time_taken);
}

int main() {
    int n;

    // User input for the number
    printf("Enter a number to calculate factorial: ");
    scanf("%d", &n);

    // Testing factorial functions
    test_factorial(n);

    return 0;
}
