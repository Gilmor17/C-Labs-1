#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// Function declarations
void applyCeil(double *x);
void applyFloor(double *x);
void analyzeString(char *str);
void decimalToHex(int num);
void reverseString(char *str, int left, int right);

void displayMenu() {
    printf("\n=== Function Menu ===\n");
    printf("1. Apply ceil(x)\n");
    printf("2. Apply floor(x)\n");
    printf("3. Analyze string properties\n");
    printf("4. Convert decimal to hexadecimal\n");
    printf("5. Reverse a string\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    double number;
    char str[100];

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter a real number: ");
                scanf("%lf", &number);
                applyCeil(&number);
                printf("Ceil: %.2f\n", number);
                break;

            case 2:
                printf("Enter a real number: ");
                scanf("%lf", &number);
                applyFloor(&number);
                printf("Floor: %.2f\n", number);
                break;

            case 3:
                printf("Enter a string: ");
                scanf("%99[^\n]", str);
                analyzeString(str);
                break;

            case 4:
                printf("Enter a decimal number: ");
                int dec;
                scanf("%d", &dec);
                printf("Hexadecimal: ");
                decimalToHex(dec);
                printf("\n");
                break;

            case 5:
                printf("Enter a string: ");
                scanf("%99[^\n]", str);
                reverseString(str, 0, strlen(str) - 1);
                printf("Reversed string: %s\n", str);
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 6);

    return 0;
}
