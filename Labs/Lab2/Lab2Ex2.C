#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void main(){
     float weight;
        double value;
        printf("Enter your weight in pounds: ");
        scanf("%f", &weight);
        value = 1770.0 * weight * 14.5;
        printf("Your weight in platinum is worth: $%.4f\n", value);
}