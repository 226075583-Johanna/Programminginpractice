/*
  
 * This program does everything the Week 7 lab asks for:
 * 1. Adds a single supplier's details
 * 2. Shows the length of strings
 * 3. Searches for a supplier
 * 4. Copies a string
 * 5. Builds a description sentence
 * 6. Stores 5 suppliers and searches through them
 */

#include <stdio.h>
#include <string.h>

int main()
{
    // ==========================================
    // PART 1: SINGLE SUPPLIER DETAILS (Tasks 1 & 2)
    // ==========================================
    printf("=== PART 1: SINGLE SUPPLIER ===\n\n");

    // 1. Create our "filing cabinets" (arrays) to store the text
    char supplierName[100];
    char email[100];
    char phone[30];
    char town[50];

    // 2. Ask for the supplier name
    printf("Enter supplier name: ");
    // fgets reads the whole line (safe for spaces)
    fgets(supplierName, sizeof(supplierName), stdin);
    // strcspn finds the Enter key (\n) and replaces it with \0 to clean the string
    supplierName[strcspn(supplierName, "\n")] = '\0';

    // 3. Ask for email
    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    // 4. Ask for phone
    printf("Enter phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    // 5. Ask for town
    printf("Enter town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = '\0';

    // 6. Display the details
    printf("\n- - SUPPLIER DETAILS - -\n");
    printf("Name : %s\n", supplierName);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town : %s\n", town);

    // 7. Show the length of the strings (Task 2)
    printf("\n- - STRING LENGTHS - -\n");
    printf("Supplier name length: %zu\n", strlen(supplierName));
    printf("Email length: %zu\n", strlen(email));
    printf("Town length: %zu\n", strlen(town));

    // ==========================================
    // PART 2: SEARCH, COPY, AND BUILD (Tasks 3, 4, & 5)
    // ==========================================
    
    // 8. Search for a supplier (Task 3)
    printf("\n- - SUPPLIER SEARCH - -\n");
    char searchName[100];
    printf("Enter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    // Compare the search name with the supplier name we entered earlier
    if (strcmp(supplierName, searchName) == 0)
    {
        printf("Supplier found: %s\n", supplierName);
    }
    else
    {
        printf("Supplier not found.\n");
    }

    // 9. Copy the supplier name (Task 4)
    printf("\n- - COPY TEST - -\n");
    char backup[100];
    strcpy(backup, supplierName); // Copy original into backup
    printf("Original: %s\n", supplierName);
    printf("Backup  : %s\n", backup);

    // 10. Build a sentence (Task 5)
    printf("\n- - DESCRIPTION - -\n");
    char description[200] = ""; // Start empty!
    strcat(description, supplierName);    // Add name
    strcat(description, " operates in "); // Add middle
    strcat(description, town);            // Add town
    strcat(description, ".");             // Add full stop
    printf("%s\n", description);

    // ==========================================
    // PART 3: 5 SUPPLIERS CHALLENGE
    // ==========================================
    printf("\n\n=== PART 3: 5 SUPPLIERS CHALLENGE ===\n\n");

    // 11. Create a 2D array. Think of it as 5 drawers, each holding 100 characters.
    char names[5][100];
    char emails[5][100];
    char phones[5][30];
    char towns[5][50];
    int i;
    int found = 0; // 0 means not found, 1 means found

    // 12. Loop 5 times to add 5 suppliers
    for (i = 0; i < 5; i++)
    {
        printf("Supplier %d\n", i + 1);

        printf("Enter name: ");
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0';

        printf("Enter email: ");
        fgets(emails[i], sizeof(emails[i]), stdin);
        emails[i][strcspn(emails[i], "\n")] = '\0';

        printf("Enter phone: ");
        fgets(phones[i], sizeof(phones[i]), stdin);
        phones[i][strcspn(phones[i], "\n")] = '\0';

        printf("Enter town: ");
        fgets(towns[i], sizeof(towns[i]), stdin);
        towns[i][strcspn(towns[i], "\n")] = '\0';

        printf("\n");
    }

    // 13. Display all 5 suppliers
    printf("=== ALL SUPPLIERS ===\n\n");
    for (i = 0; i < 5; i++)
    {
        printf("Supplier %d\n", i + 1);
        printf("  Name : %s\n", names[i]);
        printf("  Email: %s\n", emails[i]);
        printf("  Phone: %s\n", phones[i]);
        printf("  Town : %s\n", towns[i]);
        printf("\n");
    }

    // 14. Search through the 5 suppliers
    printf("=== SEARCH SUPPLIER ===\n\n");
    printf("Enter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (i = 0; i < 5; i++)
    {
        // Compare the search name with the name in drawer i
        if (strcmp(names[i], searchName) == 0)
        {
            printf("\nSupplier found!\n");
            printf("  Name : %s\n", names[i]);
            printf("  Email: %s\n", emails[i]);
            printf("  Phone: %s\n", phones[i]);
            printf("  Town : %s\n", towns[i]);
            found = 1; // Turn the light switch ON
            break;     // Stop searching, we found it!
        }
    }

    if (found == 0)
    {
        printf("\nSupplier not found.\n");
    }

    return 0;
}