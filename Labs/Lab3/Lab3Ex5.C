#include <stdio.h>

#define MAX_SIZE 20

// Function to calculate the mean
double calculate_mean(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

// Function to calculate the median
double calculate_median(int arr[], int size) {
    if (size % 2 == 0) {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        return arr[size / 2];
    }
}

// Function to calculate the mode
int calculate_mode(int arr[], int size) {
    int max_count = 0, mode = arr[0], count = 1;
    for (int i = 1; i < size; i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
        } else {
            count = 1;
        }
        if (count > max_count) {
            max_count = count;
            mode = arr[i];
        }
    }
    return mode;
}

int main() {
    int arr[MAX_SIZE], size;
    
    // Input size
    printf("Enter the number of elements (up to %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size!\n");
        return 1;
    }
    
    // Input sorted numbers
    printf("Enter %d numbers in ascending order (1-100):\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Compute mean, median, and mode
    double mean = calculate_mean(arr, size);
    double median = calculate_median(arr, size);
    int mode = calculate_mode(arr, size);
    
    // Display results
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Mode: %d\n", mode);
    
    return 0;
}
