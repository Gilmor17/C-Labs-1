#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void main(){
    char word1[20], word2[20], word3[20];
        printf("Enter three words: ");
        scanf("%s %s %s", word1, word2, word3);
        printf("Reversed: %s %s %s\n", strrev(word1), strrev(word2), strrev(word3));
}