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

    // Copy elements (risking out-of-bounds access)
    for (int i = 0; i < size; i++) {
        copy[i] = arr[i];  // Potential out-of-bounds access
    }

    return copy;
}

// Test driver function
int main() {
    int original[] = {1, 2, 3, 4, 5};  // Array with only 5 elements
    int actualSize = sizeof(original) / sizeof(original[0]);
    int largeSize = 10;  // Intentionally larger than actualSize

    printf("Original array has %d elements, but requesting copy with %d elements.\n", actualSize, largeSize);

    // Call function with a size larger than the actual array
    int *copiedArray = copyArray(original, largeSize);

    if (copiedArray != NULL) {
        // Print copied array
        printf("Copied array contents: ");
        for (int i = 0; i < largeSize; i++) {
            printf("%d ", copiedArray[i]);  // May access uninitialized memory
        }
        printf("\n");

        // Free allocated memory
        free(copiedArray);
    }

    return 0;
}
