#include <stdio.h>
#include <stdlib.h>

// Function to copy an array of integers
int* copyArray(int *arr, int size) {
    if (size <= 0) return NULL;

    // Allocate memory for the new array
    int *copy = (int*)malloc(size * sizeof(int));
    if (copy == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Copy elements
    for (int i = 0; i < size; i++) {
        copy[i] = arr[i];
    }

    return copy; // Return pointer to new array
}

// Test driver function
int main() {
    int original[] = {1, 2, 3, 4, 5};  // Sample array
    int size = sizeof(original) / sizeof(original[0]);

    // Call function to copy the array
    int *copiedArray = copyArray(original, size);

    if (copiedArray != NULL) {
        // Print original and copied arrays
        printf("Original array: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", original[i]);
        }

        printf("\nCopied array:   ");
        for (int i = 0; i < size; i++) {
            printf("%d ", copiedArray[i]);
        }
        printf("\n");

        // Free allocated memory
        free(copiedArray);
    }

    return 0;
}
