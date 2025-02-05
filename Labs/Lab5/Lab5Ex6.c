#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 5    // Maximum number of strings
#define MAX_LENGTH 100   // Maximum length of each string

// Function to append a suffix to a selected string
void appendSuffix(char *str, const char *suffix) {
    strcat(str, suffix);  // Append the suffix to the string
}

int main() {
    char strings[MAX_STRINGS][MAX_LENGTH];  // Array to store strings
    char suffix[MAX_LENGTH];  // Suffix to be appended
    int numStrings = 0, choice;

    // Input sequence of strings
    printf("Enter up to %d strings (type 'done' to stop):\n", MAX_STRINGS);
    while (numStrings < MAX_STRINGS) {
        printf("String %d: ", numStrings + 1);
        fgets(strings[numStrings], MAX_LENGTH, stdin);
        
        // Remove newline character if present
        strings[numStrings][strcspn(strings[numStrings], "\n")] = 0;

        if (strcmp(strings[numStrings], "done") == 0) {
            break;  // Exit if user types "done"
        }
        
        numStrings++;
    }

    // Ask for suffix
    printf("Enter a suffix to append: ");
    fgets(suffix, MAX_LENGTH, stdin);
    
    // Remove newline character from the suffix input
    suffix[strcspn(suffix, "\n")] = 0;

    // Display list of strings
    printf("\nSelect a string to append the suffix:\n");
    for (int i = 0; i < numStrings; i++) {
        printf("%d. %s\n", i + 1, strings[i]);
    }

    // Input to select a string
    printf("Enter the number of the string to modify (1 to %d): ", numStrings);
    scanf("%d", &choice);
    getchar(); // To consume the newline character left by scanf

    if (choice < 1 || choice > numStrings) {
        printf("Invalid choice. Exiting program.\n");
    } else {
        // Append the suffix and display the modified string
        appendSuffix(strings[choice - 1], suffix);
        printf("\nModified string: %s\n", strings[choice - 1]);
    }

    return 0;
}
