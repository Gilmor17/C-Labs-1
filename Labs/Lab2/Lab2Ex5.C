#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void main(){
    const int DAYS_IN_WEEK = 7;
        int days;
        printf("Enter number of days: ");
        scanf("%d", &days);
        printf("%d days = %d weeks and %d days\n", days, days / DAYS_IN_WEEK, days % DAYS_IN_WEEK);
}