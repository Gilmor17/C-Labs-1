#include <stdio.h>

#define SIZE 101  // Range of x, y, z from 0 to 100

// Function to calculate f(x, y, z)
double f(int x, int y, int z) {
    return x + 6 * y + 7.2 * z;
}

int main() {
    double arr[SIZE][SIZE][SIZE];  // 3D array to store the results

    // Loop through all combinations of x, y, z (0 to 100)
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            for (int z = 0; z < SIZE; z++) {
                arr[x][y][z] = f(x, y, z);  // Compute and store the result
            }
        }
    }

    // Optionally, print some values to verify (printing all would be too much)
    printf("f(0,0,0) = %.2f\n", arr[0][0][0]);
    printf("f(50,50,50) = %.2f\n", arr[50][50][50]);
    printf("f(100,100,100) = %.2f\n", arr[100][100][100]);

    return 0;
}
