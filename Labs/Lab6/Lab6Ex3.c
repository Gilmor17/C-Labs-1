#include <stdio.h>
#include <string.h>

typedef struct {
    char title[40];
    char author[40];
    float price;
} Book;

typedef struct {
    long offset;
    int book_index;
} Index;

// Function to swap two indexes
void swap(Index *a, Index *b) {
    Index temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the indexes based on a field (ascending or descending order)
void sort_index(Index indexes[], int n, int field) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int condition = 0;
            switch (field) {
                case 0: // Sort by title ascending
                    condition = strcmp(indexes[i].title, indexes[j].title) > 0;
                    break;
                case 1: // Sort by title descending
                    condition = strcmp(indexes[i].title, indexes[j].title) < 0;
                    break;
                case 2: // Sort by price ascending
                    condition = indexes[i].price > indexes[j].price;
                    break;
                case 3: // Sort by price descending
                    condition = indexes[i].price < indexes[j].price;
                    break;
            }
            if (condition) {
                swap(&indexes[i], &indexes[j]);
            }
        }
    }
}

// Function to display the books based on the indexes
void display_books(FILE *fp, Index indexes[], int n) {
    Book book;
    for (int i = 0; i < n; i++) {
        fseek(fp, indexes[i].offset, SEEK_SET);
        fread(&book, sizeof(Book), 1, fp);
        printf("Title: %s\nAuthor: %s\nPrice: $%.2f\n\n", book.title, book.author, book.price);
    }
}

int main(void) {
    // Create sample books
    Book book1 = {
        "The C Programming Language",
        "Kernighan & Ritchie",
        29.99
    };
    Book book2 = {
        "Clean Code",
        "Robert C. Martin",
        24.99
    };

    // Open the file for writing
    FILE *fp = fopen("book.dat", "wb");
    if (fp == NULL) {
        perror("Unable to open file for writing");
        return 1;
    }

    // Write the books to the file
    fwrite(&book1, sizeof(Book), 1, fp);
    fwrite(&book2, sizeof(Book), 1, fp);
    fclose(fp);

    // Create index for file offsets and store book data
    fp = fopen("book.dat", "rb");
    if (fp == NULL) {
        perror("Unable to open file for reading");
        return 1;
    }

    // Index array, assuming there are two books
    Index indexes[2];
    Book book;
    
    // Fill the indexes with file offsets
    long offset = 0;
    for (int i = 0; i < 2; i++) {
        indexes[i].offset = offset;
        indexes[i].book_index = i;
        fseek(fp, offset, SEEK_SET);
        fread(&book, sizeof(Book), 1, fp);
        strcpy(indexes[i].title, book.title); // Copy title for sorting
        indexes[i].price = book.price; // Copy price for sorting
        offset += sizeof(Book); // Move the offset by size of a book
    }

    // Sort indexes by title in ascending order
    sort_index(indexes, 2, 0);
    printf("Books sorted by title (ascending):\n");
    display_books(fp, indexes, 2);

    // Sort indexes by title in descending order
    sort_index(indexes, 2, 1);
    printf("\nBooks sorted by title (descending):\n");
    display_books(fp, indexes, 2);

    // Sort indexes by price in ascending order
    sort_index(indexes, 2, 2);
    printf("\nBooks sorted by price (ascending):\n");
    display_books(fp, indexes, 2);

    // Sort indexes by price in descending order
    sort_index(indexes, 2, 3);
    printf("\nBooks sorted by price (descending):\n");
    display_books(fp, indexes, 2);

    fclose(fp);
    return 0;
}
