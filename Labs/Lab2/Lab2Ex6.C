#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void main(){
     const float EXCHANGE_RATE = 0.92;
        float dollars;
        printf("Enter amount in dollars: ");
        scanf("%f", &dollars);
        printf("Equivalent in euros: %.2f\n", dollars * EXCHANGE_RATE);
}