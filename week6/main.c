#include <stdio.h>

int main() {
    
    float salaries[50]; 
    float budgets[10]; 
    char registrations[20][20]; 

    int choice;
    int i, j; 
    
    // Variables used for calculations and sorting
    float total, average, highest, lowest, temp;

    // --- MENU LOOP ---
    do {
        printf("\n--- MUNICIPAL INFORMATION SYSTEM ---\n");
        printf("1. Capture Employee Salaries\n");
        printf("2. Capture Department Budgets\n");
        printf("3. Capture Vehicle Registrations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            
            // --- PART A: EMPLOYEE SALARIES ---
            case 1:
                printf("\n--- ENTER 5 SALARIES ---\n");
                for (i = 0; i < 50; i++) {
                    printf("Enter salary for employee %d: ", i + 1);
                    scanf("%f", &salaries[i]);
                }

                // Display all salaries and calculate total
                printf("\nAll Salaries:\n");
                total = 0;
                highest = salaries[0]; // Set first salary as highest
                lowest = salaries[0];  // Set first salary as lowest

                for (i = 0; i < 50; i++) {
                    printf("%.2f\n", salaries[i]);
                    total = total + salaries[i];

                    if (salaries[i] > highest) {
                        highest = salaries[i];
                    }
                    if (salaries[i] < lowest) {
                        lowest = salaries[i];
                    }
                }

                average = total / 5;
                printf("Total Salary: %.2f\n", total);
                printf("Average Salary: %.2f\n", average);
                printf("Highest Salary: %.2f\n", highest);
                printf("Lowest Salary: %.2f\n", lowest);
                break;

            // --- PART B: DEPARTMENT BUDGETS ---
            case 2:
                printf("\n--- ENTER 5 BUDGETS ---\n");
                for (i = 0; i < 10; i++) {
                    printf("Enter budget for department %d: ", i + 1);
                    scanf("%f", &budgets[i]);
                }

                // Bubble Sort (Lowest to Highest)
                for (i = 0; i < 10 - 1; i++) {
                    for (j = 0; j < 5 - i - 1; j++) {
                        if (budgets[j] > budgets[j + 1]) {
                            // The Swap Logic
                            temp = budgets[j];
                            budgets[j] = budgets[j + 1];
                            budgets[j + 1] = temp;
                        }
                    }
                }

                printf("\nBudgets sorted from lowest to highest:\n");
                for (i = 0; i < 10; i++) {
                    printf("%.2f\n", budgets[i]);
                }
                break;

            // --- PART C: VEHICLE REGISTRATIONS ---
            case 3:
                printf("\n--- ENTER 5 REGISTRATIONS ---\n");
                for (i = 0; i < 20; i++) {
                    printf("Enter vehicle registration %d: ", i + 1);
                    scanf("%19s", registrations[i]); // The 19 stops buffer overflow
                }

                printf("\nAll Vehicle Registrations:\n");
                for (i = 0; i < 20; i++) {
                    printf("%s\n", registrations[i]);
                }
                break;

            case 4:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}