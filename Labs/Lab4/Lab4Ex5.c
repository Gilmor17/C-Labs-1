#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check input validity, length, first character, and most frequent character
void analyzeString(char *str) {
    // 1. Check input validity (no numeric characters)
    int isValid = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            isValid = 0;
            break;
        }
    }

    // Output validity
    if (isValid) {
        printf("Input validity: Valid (no numeric characters)\n");
    } else {
        printf("Input validity: Invalid (contains numeric characters)\n");
    }

    // 2. Output input length
    printf("Input length: %lu\n", strlen(str));

    // 3. Output input's first character
    if (strlen(str) > 0) {
        printf("First character: %c\n", str[0]);
    } else {
        printf("First character: None (empty string)\n");
    }

    // 4. Output input's most frequent character
    int freq[256] = {0};  // Frequency array for all ASCII characters
    int maxFreq = 0;
    char mostFrequentChar = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
        if (freq[(unsigned char)str[i]] > maxFreq) {
            maxFreq = freq[(unsigned char)str[i]];
            mostFrequentChar = str[i];
        }
    }

    if (maxFreq > 0) {
        printf("Most frequent character: %c\n", mostFrequentChar);
    } else {
        printf("Most frequent character: None (empty string)\n");
    }
}

int main() {
    char input[100];

    // Accepting multiple strings from the input stream
    printf("Enter strings (press Ctrl+D to stop):\n");
    while (scanf("%99[^\n]", input) != EOF) {  // Read until a newline or end of file
        // Clear input buffer after each string
        getchar();  // to consume the newline character

        printf("\nAnalyzing the input:\n");
        analyzeString(input);
        printf("\n-------------------------\n");
    }

    return 0;
}
