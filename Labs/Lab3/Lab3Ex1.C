#include <stdio.h>

int main(void) {
    long num;
    long sum = 0L; /* initialize sum to zero */
    
    printf("Please enter integers to be summed (q to quit): ");
    
    while (scanf("%ld", &num) == 1) {
        sum += num;
        printf("Please enter next integer (q to quit): ");
    }
    
    printf("Those integers sum to %ld.\n", sum);
    return 0;
}