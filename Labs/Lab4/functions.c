#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// Apply ceil(x) using math.h
void applyCeil(double *x) {
    *x = ceil(*x);
}

// Apply floor(x) using math.h
void applyFloor(double *x) {
    *x = floor(*x);
}

// Analyze string: validity, length, first char, most frequent char
void analyzeString(char *str) {
    int isValid = 1, freq[256] = {0}, len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isdigit(str[i])) isValid = 0;
        freq[(unsigned char)str[i]]++;
    }

    char mostFrequent = str[0];
    for (int i = 1; i < len; i++) {
        if (freq[(unsigned char)str[i]] > freq[(unsigned char)mostFrequent])
            mostFrequent = str[i];
    }

    printf("Input validity: %s\nLength: %d\nFirst char: %c\nMost frequent char: %c\n",
           isValid ? "Valid" : "Invalid", len, str[0], mostFrequent);
}

// Convert decimal to hexadecimal recursively
void decimalToHex(int num) {
    if (num == 0) return;
    decimalToHex(num / 16);
    int remainder = num % 16;
    printf("%c", remainder < 10 ? '0' + remainder : 'A' + remainder - 10);
}

// Reverse string recursively
void reverseString(char *str, int left, int right) {
    if (left >= right) return;
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;
    reverseString(str, left + 1, right - 1);
}
