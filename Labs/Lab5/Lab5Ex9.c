#include <stdio.h>
#include <string.h>

#define NLEN 30

// Define string_t as a typedef for a string (character array)
typedef char string_t[NLEN];

// Define name_t as a typedef for the namect struct
typedef struct {
    string_t fname;
    string_t lname;
    int letters;
} name_t;

// Function to update the letter count in the name_t struct
name_t update_info(name_t info) {
    info.letters = strlen(info.fname) + strlen(info.lname);
    return info;
}

int main(void) {
    // Create a name_t type variable and initialize it
    name_t person = {"Neville", "Grech", 0};

    // Update the person's information
    person = update_info(person);

    // Print the result
    printf("%s %s, your name contains %d letters.\n",
           person.fname, person.lname, person.letters);

    return 0;
}
