/*
 * PAP521S - Week 10: File Handling
 * This program saves and loads Employee data using BOTH text files and binary files.
 */

#include <stdio.h>
#include <stdlib.h>

// A simple structure to hold employee data
typedef struct {
    int id;
    char name[50];
    double salary;
} Employee;

// Function Prototypes
void saveText(Employee emp);
void loadText();
void saveBinary(Employee emp);
void loadBinary();

int main() {
    int choice;
    Employee emp;

    do {
        printf("\n--- MFMS WEEK 10 FILE HANDLING ---\n");
        printf("1. Add Employee & Save to TEXT file\n");
        printf("2. Load Employees from TEXT file\n");
        printf("3. Add Employee & Save to BINARY file\n");
        printf("4. Load Employees from BINARY file\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &emp.id);
                printf("Enter Name (no spaces): ");
                scanf("%49s", emp.name);
                printf("Enter Salary: ");
                scanf("%lf", &emp.salary);
                saveText(emp);
                break;
            case 2:
                loadText();
                break;
            case 3:
                printf("Enter ID: ");
                scanf("%d", &emp.id);
                printf("Enter Name (no spaces): ");
                scanf("%49s", emp.name);
                printf("Enter Salary: ");
                scanf("%lf", &emp.salary);
                saveBinary(emp);
                break;
            case 4:
                loadBinary();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 5);

    return 0;
}

// Saves ONE employee to a text file
void saveText(Employee emp) {
    // "a" means append (add to the end). We don't want to overwrite old data!
    FILE *fp = fopen("employees.txt", "a");
    
    // If the file couldn't be opened, stop.
    if (fp == NULL) {
        printf("Error: Could not open text file.\n");
        return;
    }
    
    // Write the data using fprintf (just like printf, but to a file)
    fprintf(fp, "%d %s %.2f\n", emp.id, emp.name, emp.salary);
    
    // Always close the file!
    fclose(fp);
    printf("Saved to employees.txt successfully!\n");
}

// Reads all employees from the text file
void loadText() {
    Employee temp;
    // "r" means read mode
    FILE *fp = fopen("employees.txt", "r");
    
    if (fp == NULL) {
        printf("No text file found yet.\n");
        return;
    }
    
    printf("\n--- TEXT FILE DATA ---\n");
    // Keep reading as long as we find exactly 3 pieces of data
    while (fscanf(fp, "%d %49s %lf", &temp.id, temp.name, &temp.salary) == 3) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", temp.id, temp.name, temp.salary);
    }
    
    fclose(fp);
}

// Saves ONE employee to a binary file (.dat)
void saveBinary(Employee emp) {
    // "ab" means append binary (computer language, not human-readable)
    FILE *fp = fopen("employees.dat", "ab");
    
    if (fp == NULL) {
        printf("Error: Could not open binary file.\n");
        return;
    }
    
    // fwrite writes the raw bytes of the struct directly to the file
    fwrite(&emp, sizeof(Employee), 1, fp);
    
    fclose(fp);
    printf("Saved to employees.dat (Binary) successfully!\n");
}

// Reads all employees from the binary file
void loadBinary() {
    Employee temp;
    // "rb" means read binary
    FILE *fp = fopen("employees.dat", "rb");
    
    if (fp == NULL) {
        printf("No binary file found yet.\n");
        return;
    }
    
    printf("\n--- BINARY FILE DATA ---\n");
    // fread reads the raw bytes back into our struct. 
    // It returns 1 if it successfully read one Employee.
    while (fread(&temp, sizeof(Employee), 1, fp) == 1) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", temp.id, temp.name, temp.salary);
    }
    
    fclose(fp);
}