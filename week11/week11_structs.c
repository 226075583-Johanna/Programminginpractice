#include <stdio.h>
#include <string.h>

// 1. The "Blank Form" (Structure)
typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

int main() {
    // 2. An array of structures (A drawer of record cards)
    Employee staff[3] = {
        {1001, "Maria", 18500.50},
        {1002, "Simon", 17200.00},
        {1003, "Anna", 21000.75}
    };

    printf("--- EMPLOYEE RECORDS ---\n");
    
    // 3. Loop through the array and print
    for (int i = 0; i < 3; i++) {
        printf("ID: %d | Name: %s | Salary: N$%.2f\n", 
               staff[i].id, staff[i].name, staff[i].salary);
    }

    return 0;
}