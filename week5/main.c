#include <stdio.h> 
 
int main() { 
 
    float salary; 
    float total = 0; 
    float highest = 0; 
    float lowest = 0; 
    float average; 
    int numEmployees = 5;
 
    for (int i = 1; i <= numEmployees; i++) { 
 
        printf("Enter salary for employee %d: ", i); 
        scanf("%f", &salary); 
 
        total = total + salary; 
 
        if (i == 1) { 
            highest = salary; 
            lowest = salary; 
        } 
 
 
        if (salary > highest) { 
            highest = salary; 
        } 
 
        if (salary < lowest) { 
            lowest = salary; 
        } 
    } 
 
    average = total / 50; 
 
    printf("\n--- Salary Report ---\n"); 
    printf("Average salary: %.2f\n", average); 
    printf("Highest salary: : %.2f\n", highest); 
    printf("Lowest salary: %.2f\n", lowest); 
 
    return 0; 
} 
 
