#include <stdio.h>
#include <stdlib.h>  // For atoi()

int main(int argc, char *argv[]) {
    // Check if there are exactly 3 arguments (program name + 2 arguments)
    if (argc != 3) {
        printf("Error: Please provide exactly two numeric arguments.\n");
        return 1;  // Exit with error code
    }

    // Convert the arguments to integers
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    // Check if the conversion resulted in valid numbers
    if (num1 == 0 && argv[1][0] != '0') {
        printf("Error: The first argument is not a valid number.\n");
        return 1;
    }
    if (num2 == 0 && argv[2][0] != '0') {
        printf("Error: The second argument is not a valid number.\n");
        return 1;
    }

    // Add the two numbers
    int sum = num1 + num2;

    // Print the result
    printf("The sum of %d and %d is %d.\n", num1, num2, sum);

    return 0;  // Success
}
