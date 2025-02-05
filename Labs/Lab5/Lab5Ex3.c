#include <stdio.h>

#define SIZE 10

int sum(int *ar, int n);  // Function prototype using pointer syntax

int main(void) {
    int marbles[SIZE] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
    long answer = sum(marbles, SIZE);  // Passing array as pointer
    printf("The total number of marbles is %ld.\n", answer);
    printf("The size of marbles is %zu bytes.\n", sizeof marbles);

    return 0;
}

int sum(int *ar, int n) {  // Parameter is a pointer
    int total = 0;
    for (int i = 0; i < n; i++)
        total += *(ar + i);  // Pointer dereferencing (ar[i] -> *(ar + i))
    printf("The size of ar is %zu bytes.\n", sizeof ar);
    return total;
}
