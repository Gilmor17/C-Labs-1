#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Iterative Fibonacci function
long fib_iterative(int n) {
    long a = 0, b = 1, temp;
    if (n == 0) return a;
    if (n == 1) return b;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

// Recursive Fibonacci function
long fib_recursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Function to test the performance (time and stack usage) of each Fibonacci function
void test_fibonacci(int n) {
    clock_t start, end;
    double time_taken;

    // Test iterative Fibonacci
    start = clock();
    long iterative_result = fib_iterative(n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Iterative Fibonacci of %d is %ld, Time taken: %f seconds\n", n, iterative_result, time_taken);

    // Test recursive Fibonacci
    start = clock();
    long recursive_result = fib_recursive(n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Recursive Fibonacci of %d is %ld, Time taken: %f seconds\n", n, recursive_result, time_taken);
}

int main() {
    int n;

    // User input for the number
    printf("Enter a number to calculate the Fibonacci sequence: ");
    scanf("%d", &n);

    // Testing Fibonacci functions
    test_fibonacci(n);

    return 0;
}
