#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(){
    void int_to_char() {
        int num;
        printf("Enter an integer: ");
        scanf("%d", &num);
        printf("Character: %c\n", num);
        printf("Octal: %o\nHex: %X\n", num, num);
    }
}
