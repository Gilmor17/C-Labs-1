#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100

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

// Function to load index from disk
void load_index(const char *filename, Index indexes[], int *n) {
    FILE *index_fp = fopen(filename, "rb");
    if (index_fp == NULL) return;  // No index file found
    fread(n, sizeof(int), 1, index_fp);  // Read the number of records
    fread(indexes, sizeof(Index), *n, index_fp);  // Read the indexes
    fclose(index_fp);
}

// Function to save index to disk
void save_index(const char *filename, Index indexes[], int n) {
    FILE *index_fp = fopen(filename, "wb");
    if (index_fp == NULL) {
        perror("Unable to open index file for writing");
        return;
    }
    fwrite(&n, sizeof(int), 1, index_fp);  // Write the number of records
    fwrite(indexes, sizeof(Index), n, index_fp);  // Write the indexes
    fclose(index_fp);
}

int main(void) {
    Book book;
    Index index_title_asc[MAX_BOOKS], index_title_desc[MAX_BOOKS], index_price_asc[MAX_BOOKS];
    int book_count = 0;
    
    // Load the indexes from disk (if they exist)
    load_index("index_title_asc.dat", index_title_asc, &book_count);
    load_index("index_title_desc.dat", index_title_desc, &book_count);
    load_index("index_price_asc.dat", index_price_asc, &book_count);

    // Open the file for appending new books
    FILE *fp = fopen("book.dat", "ab+");
    if (fp == NULL) {
        perror("Unable to open file for appending");
        return 1;
    }

    // Sample input for adding new books
    while (1) {
        printf("Enter book title (or 'exit' to stop): ");
        fgets(book.title, 40, stdin);
        book.title[strcspn(book.title, "\n")] = 0;  // Remove trailing newline

        if (strcmp(book.title, "exit") == 0) {
            break;
        }

        printf("Enter author: ");
        fgets(book.author, 40, stdin);
        book.author[strcspn(book.author, "\n")] = 0;  // Remove trailing newline

        printf("Enter price: ");
        scanf("%f", &book.price);
        getchar();  // Consume newline after scanf

        // Write the new book to the file
        fseek(fp, 0, SEEK_END);
        long offset = ftell(fp);
        fwrite(&book, sizeof(Book), 1, fp);

        // Add the new book to the indexes
        index_title_asc[book_count].offset = offset;
        strcpy(index_title_asc[book_count].title, book.title);
        index_title_asc[book_count].price = book.price;

        index_title_desc[book_count] = index_title_asc[book_count];
        index_price_asc[book_count] = index_title_asc[book_count];

        book_count++;
    }

    // Sort indexes after adding all books
    sort_index(index_title_asc, book_count, 0);  // Sort by title ascending
    sort_index(index_title_desc, book_count, 1);  // Sort by title descending
    sort_index(index_price_asc, book_count, 2);  // Sort by price ascending

    // Display the books sorted by title in ascending order
    printf("\nBooks sorted by title (ascending):\n");
    display_books(fp, index_title_asc, book_count);

    // Display the books sorted by title in descending order
    printf("\nBooks sorted by title (descending):\n");
    display_books(fp, index_title_desc, book_count);

    // Display the books sorted by price in ascending order
    printf("\nBooks sorted by price (ascending):\n");
    display_books(fp, index_price_asc, book_count);

    // Save the updated indexes to disk
    save_index("index_title_asc.dat", index_title_asc, book_count);
    save_index("index_title_desc.dat", index_title_desc, book_count);
    save_index("index_price_asc.dat", index_price_asc, book_count);

    fclose(fp);
    return 0;
}
