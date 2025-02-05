#include <stdio.h>

#define PIN 1234
#define MAX_ATTEMPTS 5

int main() {
    int attempt = 0, input;
    
    while (attempt < MAX_ATTEMPTS) {
        printf("Enter PIN: ");
        scanf("%d", &input);
        
        if (input == PIN) {
            printf("Access granted.\n");
            return 0;
        } else {
            printf("Incorrect PIN.\n");
        }
        attempt++;
    }
    
    printf("Too many incorrect attempts. Access locked.\n");
    return 1;
}
