#include <stdio.h>
#include <stdlib.h>

#define MIN_RANGE 0.0
#define MAX_RANGE 100.0
#define OUTPUT_FILE "filtered_numbers.txt"

int main() {
    FILE *outfile = fopen(OUTPUT_FILE, "w");
    if (!outfile) {
        perror("Error opening output file");
        return 1;
    }

    double num;
    int valid_inputs = 0, invalid_inputs = 0;

    printf("Enter real numbers (Ctrl+D to end input):\n");
    while (scanf("%lf", &num) == 1) {
        if (num >= MIN_RANGE && num <= MAX_RANGE) {
            fprintf(outfile, "%lf\n", num);
            valid_inputs++;
        } else {
            printf("Warning: Number out of range - %lf\n", num);
            invalid_inputs++;
        }
    }
    
    if (ferror(stdin)) {
        printf("Error reading input.\n");
    }
    
    fclose(outfile);
    printf("Processing complete. %d valid numbers saved, %d invalid inputs encountered.\n", valid_inputs, invalid_inputs);
    return 0;
}
