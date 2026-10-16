/*
 * PAP521S - Programming in Practice
 * Week 8: Functions in C
 * This program is a menu-driven MFMS that uses reusable functions.
 */

#include <stdio.h>

// ==========================================
// FUNCTION PROTOTYPES (Promises to the compiler)
// We tell the compiler: "Hey, these functions exist. I'll define them later."
// ==========================================
void displayWelcome(void);
void displayMenu(void);
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);

// ==========================================
// MAIN FUNCTION (The boss)
// ==========================================
int main()
{
    int choice;
    int employeeIDs[] = {101, 102, 103, 104, 105}; // Sample data to search through

    displayWelcome(); // Call the welcome function

    do
    {
        displayMenu(); // Call the menu function
        scanf("%d", &choice); // Get user's choice

        switch(choice)
        {
            case 1:
                // Calculate VAT
                float amount;
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("VAT: %.2f\n", calculateVAT(amount));
                break;

            case 2:
                // Calculate Salary
                float basic, housing, transport;
                printf("Enter basic salary: ");
                scanf("%f", &basic);
                printf("Enter housing allowance: ");
                scanf("%f", &housing);
                printf("Enter transport allowance: ");
                scanf("%f", &transport);
                printf("Gross Salary: %.2f\n", calculateSalary(basic, housing, transport));
                break;

            case 3:
                // Calculate Budget
                float revenue, expenses;
                printf("Enter revenue: ");
                scanf("%f", &revenue);
                printf("Enter expenses: ");
                scanf("%f", &expenses);
                float balance = calculateBudget(revenue, expenses);
                printf("Budget balance: %.2f\n", balance);
                
                // Tell the user if it's surplus, deficit, or balanced
                if (balance > 0) 
                    printf("Status: SURPLUS\n");
                else if (balance < 0) 
                    printf("Status: DEFICIT\n");
                else 
                    printf("Status: BALANCED\n");
                break;

            case 4:
                // Search Employee
                int searchID;
                printf("Enter employee ID to search: ");
                scanf("%d", &searchID);
                int pos = searchEmployee(searchID, employeeIDs, 5);
                if (pos != -1) 
                    printf("Employee found at position %d\n", pos);
                else 
                    printf("Employee not found.\n");
                break;

            case 5:
                // Exit
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5); // Keep looping until user chooses 5

    return 0;
}

// ==========================================
// FUNCTION DEFINITIONS (The actual machines)
// ==========================================

// Task 1: Display Welcome Message
void displayWelcome(void)
{
    printf("======================================\n");
    printf("  WELCOME TO THE MFMS\n");
    printf("======================================\n");
}

// Task 5: Display Menu
void displayMenu(void)
{
    printf("\n--- MAIN MENU ---\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

// Task 2: Calculate VAT (15%)
float calculateVAT(float amount)
{
    return amount * 0.15; 
}

// Task 3: Calculate Gross Salary
float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

// Task 4: Calculate Budget Balance
float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

// Task 6: Search for an Employee ID
int searchEmployee(int id, int ids[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i; // Found it! Return the position (index).
        }
    }
    return -1; // Not found.
}