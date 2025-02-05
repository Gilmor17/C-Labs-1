#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);

int main(void)
{
    int x, y;

    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    printf("The sum of %d and %d is: %d\n", x, y, add(x, y));

    printf("The difference between %d and %d is: %d\n", x, y, subtract(x, y));

    printf("The product of %d and %d is: %d\n", x, y, multiply(x, y));

    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}