#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void main() {
        int n;
        printf("Enter a number: ");
        scanf("%d", &n);
        printf("Factorial: %ld\n", factorial(n));
        return 0;
    }
    
long factorial(int n) {
        long result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
}