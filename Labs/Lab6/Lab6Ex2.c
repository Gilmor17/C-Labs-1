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

// Function to replace all occurrences of a word in a line of text
void replace_word_in_line(FILE *output_file, const char *line, const char *old_word, const char *new_word) {
    const char *pos = line;
    size_t old_word_len = strlen(old_word);
    size_t new_word_len = strlen(new_word);

    // Temporary buffer to hold the new content
    char result[1024];
    result[0] = '\0';  // Start with an empty string

    while ((pos = strstr(pos, old_word)) != NULL) {
        // Check if it's a whole word
        if (is_whole_word(line, old_word, pos - line)) {
            // Copy the part before the word
            strncat(result, line, pos - line);

            // Append the new word
            strcat(result, new_word);

            // Move the position past the old word
            pos += old_word_len;
            line = pos;
        } else {
            // If it's not a whole word, just copy the current character
            strncat(result, line, 1);
            pos++;
            line = pos;
        }
    }

    // Append the remaining part of the line (after the last occurrence)
    strcat(result, line);

    // Write the modified content to the output file
    fputs(result, output_file);
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

    // Open the input file for reading
    FILE *input_file = fopen(filename, "r");
    if (input_file == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    // Create a temporary file for writing the modified content
    FILE *temp_file = fopen("tempfile.txt", "w");
    if (temp_file == NULL) {
        perror("Error creating temporary file");
        fclose(input_file);
        return 1;
    }

    // Process the file line by line
    char line[1024];  // Buffer for reading each line
    while (fgets(line, sizeof(line), input_file) != NULL) {
        replace_word_in_line(temp_file, line, old_word, new_word);
    }

    // Close the files
    fclose(input_file);
    fclose(temp_file);

    // Replace the original file with the modified content
    if (remove(filename) != 0) {
        perror("Error deleting original file");
        return 1;
    }

    if (rename("tempfile.txt", filename) != 0) {
        perror("Error renaming temporary file");
        return 1;
    }

    printf("File content updated successfully.\n");
    return 0;
}
