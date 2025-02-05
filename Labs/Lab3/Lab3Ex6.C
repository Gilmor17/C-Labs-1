#include <stdio.h>

#define FIRST_BRACKET 10000
#define SECOND_BRACKET 8000
#define FIRST_RATE 0.18
#define SECOND_RATE 0.20
#define THIRD_RATE 0.25
#define ICT_REBATE 0.05
#define GREEN_INCENTIVE 15000

int main() {
    double income, tax = 0.0;
    char ict, green;
    
    printf("Enter your total income: ");
    scanf("%lf", &income);
    
    printf("Are you working in the ICT industry? (y/n): ");
    scanf(" %c", &ict);
    
    printf("Do you collect old electronic equipment for green disposal? (y/n): ");
    scanf(" %c", &green);
    
    double first_bracket = (green == 'y' || green == 'Y') ? GREEN_INCENTIVE : FIRST_BRACKET;
    
    if (income <= first_bracket) {
        tax = income * FIRST_RATE;
    } else if (income <= first_bracket + SECOND_BRACKET) {
        tax = first_bracket * FIRST_RATE + (income - first_bracket) * SECOND_RATE;
    } else {
        tax = first_bracket * FIRST_RATE + SECOND_BRACKET * SECOND_RATE + (income - first_bracket - SECOND_BRACKET) * THIRD_RATE;
    }
    
    if (ict == 'y' || ict == 'Y') {
        tax *= (1 - ICT_REBATE);
    }
    
    printf("Your total tax amount is: €%.2f\n", tax);
    
    return 0;
}
