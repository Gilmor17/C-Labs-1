/* two_func.c -- a program using a parameterized function */

#include <stdio.h>

void butler(const char *name); /* Function prototype with a parameter */

int main(void)
{
    printf("I will summon the butler function.\n");

    /* Call the butler function with a name argument */
    butler("James");

    printf("Yes. Bring me some tea and writeable CD-ROMs.\n");

    return 0;
}

/* Function definition with a parameter */
void butler(const char *name)
{
    printf("You rang, %s?\n", name);
}
