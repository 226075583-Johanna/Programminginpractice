// This is the BOSS file. It connects everything.
#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "reports.h"
#include "utilities.h"

int main() {
    int choice;
    do {
        printf("\n--- MFMS WEEK 9 ---\n");
        printf("1. Add Employee\n");
        printf("2. Add Budget\n");
        printf("3. Show Report\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addEmployee(); break; // Calls the employee machine
            case 2: addBudget(); break;   // Calls the budget machine
            case 3: showReport(); break;  // Calls the report machine
            case 4: printf("Goodbye.\n"); break;
            default: printf("Invalid choice.\n");
        }
        // If the user didn't exit, pause the screen so they can read the output
        if (choice != 4) pauseScreen(); 
    } while (choice != 4);
    return 0;
}