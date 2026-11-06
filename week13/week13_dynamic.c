#include <stdio.h>
#include <stdlib.h>

// The record card
typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

int main(void) {
    int capacity = 2; // Start with room for 2 employees
    int count = 0;    // How many employees we actually have
    int i;
    Employee *employees = NULL; // The guest list (starts empty)
    Employee *bigger;           // Temp pointer for safe resizing
    Employee e;

    // TODO 1: Ask the computer for memory (malloc)
    employees = malloc(capacity * sizeof(Employee));
    if (employees == NULL) {
        printf("Out of memory!\n");
        return 1;
    }

    printf("Employee ID (0 to stop): ");
    scanf("%d", &e.id);

    while (e.id != 0) {
        printf("Name (one word): ");
        scanf("%29s", e.name);
        printf("Salary: ");
        scanf("%lf", &e.salary);

        // TODO 2: If the array is full, double the capacity (realloc)
        if (count == capacity) {
            capacity = capacity * 2;
            
            // We use 'bigger' because if realloc fails, it returns NULL. 
            bigger = realloc(employees, capacity * sizeof(Employee));
            
            if (bigger == NULL) {
                printf("Out of memory during resize!\n");
                free(employees);
                return 1;
            }
            employees = bigger; // Success! Update the main pointer
            printf("(Array grown to %d slots)\n", capacity);
        }

        // TODO 3: Store the employee and increment the count
        employees[count] = e;
        count++;

        printf("Employee ID (0 to stop): ");
        scanf("%d", &e.id);
    }

    // TODO 4: Print all employees and the final count/capacity
    printf("\n--- EMPLOYEE LIST ---\n");
    for (i = 0; i < count; i++) {
        printf("%d %s N$%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
    printf("Employees: %d | Capacity: %d\n", count, capacity);

    // TODO 5: Give the memory back to the computer (free)
    free(employees);
    employees = NULL; 

    return 0;
}