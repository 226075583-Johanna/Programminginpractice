#include <stdio.h>

// A simple structure to test pointers with
typedef struct {
    int id;
    double salary;
} Employee;

// 1. Swap function using POINTERS (addresses)
void swapSalaries(double *a, double *b) {
    double temp = *a; // Go to address a, grab the value
    *a = *b;          // Put b's value into a's address
    *b = temp;        // Put the temp value into b's address
}

// 2. Update structure using POINTERS (arrow operator ->)
void giveRaise(Employee *e, double amount) {
    e->salary = e->salary + amount; // e->salary means (*e).salary
}

int main() {
    printf("--- POINTERS TEST ---\n\n");

    // Test 1: Swapping
    double sal1 = 15000.00;
    double sal2 = 20000.00;
    
    printf("Before Swap: Sal1 = %.2f, Sal2 = %.2f\n", sal1, sal2);
    swapSalaries(&sal1, &sal2); // Pass the ADDRESSES using &
    printf("After Swap:  Sal1 = %.2f, Sal2 = %.2f\n\n", sal1, sal2);

    // Test 2: Modifying a Structure
    Employee emp = {101, 10000.00};
    printf("Before Raise: Employee %d makes %.2f\n", emp.id, emp.salary);
    
    giveRaise(&emp, 2500.00); // Pass the ADDRESS of the employee
    printf("After Raise:  Employee %d makes %.2f\n", emp.id, emp.salary);

    return 0;
}