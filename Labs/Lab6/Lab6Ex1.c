#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a word is a whole word (not part of another word)
int is_whole_word(const char *str, const char *word, size_t start) {
    // Check if the start of the match is a word boundary
    if (start > 0 && isalpha(str[start - 1])) {
        return 0;  // Not a whole word (part of another word)
    }
    // Check if the end of the match is a word boundary
    if (str[start + strlen(word)] != '\0' && isalpha(str[start + strlen(word)])) {
        return 0;  // Not a whole word (part of another word)
    }
    return 1;  // It's a whole word
}

// Function to replace all occurrences of a word in a string
void replace_word_in_text(char **text, const char *old_word, const char *new_word) {
    char *pos = *text;
    size_t old_word_len = strlen(old_word);
    size_t new_word_len = strlen(new_word);
    size_t text_len = strlen(*text);

    // Temporary buffer to hold the new content
    char *result = malloc(text_len + 1);
    result[0] = '\0';  // Start with an empty string

    while ((pos = strstr(pos, old_word)) != NULL) {
        // Check if it's a whole word
        if (is_whole_word(*text, old_word, pos - *text)) {
            // Copy the part before the word
            strncat(result, *text, pos - *text);

            // Append the new word
            strcat(result, new_word);

            // Move the position past the old word
            pos += old_word_len;
            *text = pos;
        } else {
            // If it's not a whole word, just copy the current character
            strncat(result, *text, 1);
            pos++;
            *text = pos;
        }
    }

    // Append the remaining part of the text
    strcat(result, *text);

    // Replace the original text with the result
    free(*text);
    *text = result;
}

// Function to read the content of the file into memory
char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);  // Go to the end of the file
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);  // Go back to the beginning of the file

    // Allocate memory to store the entire file content
    char *content = malloc(file_size + 1);
    if (content == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    fread(content, 1, file_size, file);  // Read the file content
    content[file_size] = '\0';  // Null-terminate the string

    fclose(file);
    return content;
}

// Function to write the modified content back to the file
void write_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    fputs(content, file);  // Write the content to the file
    fclose(file);
}

int main() {
    char filename[100];
    char old_word[50], new_word[50];

    // Get user input for the file name and words
    printf("Enter the name of the text file: ");
    scanf("%s", filename);
    printf("Enter the word to search for: ");
    scanf("%s", old_word);
    printf("Enter the word to replace it with: ");
    scanf("%s", new_word);

    // Read the file content into memory
    char *text = read_file(filename);
    if (text == NULL) {
        return 1;  // Exit on error
    }

    // Replace all occurrences of the old word with the new word
    replace_word_in_text(&text, old_word, new_word);

    // Write the modified content back to the file
    write_file(filename, text);

    // Clean up memory
    free(text);

    printf("File content updated successfully.\n");

    return 0;
}
