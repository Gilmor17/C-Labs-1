#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 5  // For simplicity, we'll work with 5 employees

// Define the Employee struct
typedef struct {
    char name[50];
    char surname[50];
    int id;
    double salary;
} Employee;

// Function to compare employees by ID (ascending)
int compareByID(const void *a, const void *b) {
    Employee *empA = (Employee *)a;
    Employee *empB = (Employee *)b;
    return empA->id - empB->id;  // Ascending order by ID
}

// Function to compare employees by surname (alphabetical order)
int compareBySurname(const void *a, const void *b) {
    Employee *empA = (Employee *)a;
    Employee *empB = (Employee *)b;
    return strcmp(empA->surname, empB->surname);  // Alphabetical order by surname
}

// Function to print the employee list
void printEmployees(Employee employees[], int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s %s, Salary: %.2f\n",
               employees[i].id, employees[i].name, employees[i].surname, employees[i].salary);
    }
}

int main() {
    // Initialize an array of employees
    Employee employees[MAX_EMPLOYEES] = {
        {"John", "Doe", 105, 4500.00},
        {"Jane", "Smith", 103, 5500.00},
        {"Alice", "Brown", 102, 4800.00},
        {"Bob", "Davis", 101, 5300.00},
        {"Charlie", "Miller", 104, 4900.00}
    };

    printf("Employee list sorted by ID (ascending):\n");
    // Sort by ID using qsort
    qsort(employees, MAX_EMPLOYEES, sizeof(Employee), compareByID);
    printEmployees(employees, MAX_EMPLOYEES);

    printf("\nEmployee list sorted by surname (alphabetical):\n");
    // Sort by surname using qsort
    qsort(employees, MAX_EMPLOYEES, sizeof(Employee), compareBySurname);
    printEmployees(employees, MAX_EMPLOYEES);

    return 0;
}
