#include <stdio.h>
#include <string.h>

// Function to convert decimal number to hexadecimal using recursion
void decimalToHexadecimal(int num) {
    if (num == 0) {
        return;
    }
    
    // Recursive call before printing the current digit
    decimalToHexadecimal(num / 16);
    
    // Get the current hexadecimal digit
    int remainder = num % 16;
    if (remainder < 10) {
        printf("%d", remainder);  // Print digits 0-9
    } else {
        printf("%c", remainder - 10 + 'A');  // Print letters A-F for 10-15
    }
}

// Function to reverse a character string using recursion
void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return;  // Base case: if the start index is greater than or equal to the end index, stop the recursion
    }
    
    // Swap characters at positions 'start' and 'end'
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    
    // Recursive call for the next pair of characters
    reverseString(str, start + 1, end - 1);
}

int main() {
    // Test the decimalToHexadecimal function
    int decimal;
    printf("Enter a decimal number to convert to hexadecimal: ");
    scanf("%d", &decimal);
    printf("Hexadecimal representation: ");
    if (decimal == 0) {
        printf("0");  // Handle the case when the number is 0
    } else {
        decimalToHexadecimal(decimal);
    }
    printf("\n");

    // Test the reverseString function
    char str[100];
    printf("Enter a string to reverse: ");
    getchar();  // Clear the newline left by previous scanf
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;
    
    printf("Reversed string: ");
    reverseString(str, 0, strlen(str) - 1);
    printf("%s\n", str);

    return 0;
}
