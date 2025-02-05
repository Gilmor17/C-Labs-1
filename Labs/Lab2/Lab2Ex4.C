#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void main(){
    struct Employee {
            char name[11];
            char surname[11];
            int age;
            float salary;
        } employees[10];
        int count = 0;
        float total_salary = 0;
        while (count < 10) {
            printf("Enter Name, Surname, Age, Monthly Salary: ");
            scanf("%10s %10s %d %f", employees[count].name, employees[count].surname, &employees[count].age, &employees[count].salary);
            total_salary += employees[count].salary;
            count++;
            if (count % 5 == 0) {
                printf("%-5s %-10s %-10s %-5s %-10s %-10s\n", "#", "Name", "Surname", "Age", "Salary", "Yearly");
                for (int i = 0; i < count; i++) {
                    printf("%-5d %-10s %-10s %-5d %-10.2f %-10.2f\n", i+1, employees[i].name, employees[i].surname, employees[i].age, employees[i].salary, employees[i].salary * 13);
                }
            }
        }
        printf("Average Salary: %.2f\n", total_salary / 10);
}