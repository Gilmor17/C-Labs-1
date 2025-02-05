#include <stdio.h>

#define MAX 10

int main() {
    // Print the header
    printf("Multiplication Table (1 to 10)\n");
    printf("-----------------------------------\n");
    
    // Print column headers
    printf("    ");
    for (int i = 1; i <= MAX; i++) {
        printf("%4d", i);
    }
    printf("\n");
    
    // Print table
    for (int i = 1; i <= MAX; i++) {
        printf("%4d", i);
        for (int j = 1; j <= MAX; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
    
    return 0;
}
