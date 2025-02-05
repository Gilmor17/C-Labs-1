// fathm_ft.c -- converts 2 fathoms to feet

#include <stdio.h>

int main(void)

{

    int feet, fathoms; // feet and fathoms are variable names



    fathoms = 2; // lvalues = fathoms, rvalues = 2

    feet = 6 * fathoms;  // lvalues = feet, rvalues = 6 * fathoms

    printf("There are %d feet in %d fathoms!\n", feet, fathoms);//rvalue = feet,fathoms

    printf("Yes, I said %d feet!\n", 6 * fathoms);//rvalue = 6 * fathoms



    return 0;

}