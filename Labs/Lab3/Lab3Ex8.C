#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main() {
    char word[MAX_WORD_LENGTH];
    char prev_char = '\0';
    int errors = 0;
    int space_flag = 0;
    
    printf("Enter text (Ctrl+D to end input):\n");
    
    while (scanf("%99s", word) == 1) {
        int length = strlen(word);
        int has_hyphen = strchr(word, '-') != NULL;
        int uppercase_error = 0;
        
        if (length > 10 && !has_hyphen) {
            printf("Warning: Long word without hyphen - %s\n", word);
            errors++;
        }
        
        for (int i = 1; i < length; i++) {
            if (isupper(word[i])) {
                uppercase_error = 1;
                break;
            }
        }
        
        if (uppercase_error) {
            printf("Warning: Uppercase beyond first letter - %s\n", word);
            errors++;
        }
        
        if (!isalpha(word[0])) {
            printf("Warning: Word starts with non-alphabetic character - %s\n", word);
            errors++;
        }
        
        if (prev_char == ' ' && ispunct(word[0])) {
            printf("Warning: Punctuation preceded by a space - %s\n", word);
            errors++;
        }
        
        if (prev_char == ' ' && space_flag) {
            printf("Warning: Repeated spaces detected\n");
            errors++;
        }
        
        prev_char = word[length - 1];
        space_flag = (prev_char == ' ');
    }
    
    if (errors == 0) {
        printf("No errors found\n");
    } else if (errors == 1) {
        printf("1 error found\n");
    } else {
        printf("%d errors found\n", errors);
    }
    
    return 0;
}
