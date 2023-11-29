#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMPLOYEES 100

struct Employee {
    char name[MAX_NAME_LENGTH];
};

void readDataFromFile(struct Employee employees[], int *numEmployees, const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    *numEmployees = 0;

    while (*numEmployees < MAX_EMPLOYEES && fscanf(file, "%s", employees[*numEmployees].name) == 1) {
        (*numEmployees)++;
    }

    fclose(file);
}

void printEmployees(struct Employee employees[], int numEmployees) {
    for (int i = 0; i < numEmployees; ++i) {
        printf("%s\n", employees[i].name);
    }
}

void bubbleSort(struct Employee employees[], int numEmployees) {
    for (int i = 0; i < numEmployees - 1; ++i) {
        for (int j = 0; j < numEmployees - i - 1; ++j) {
            if (strcmp(employees[j].name, employees[j + 1].name) > 0) {
                // Swap the employees
                struct Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

void selectionSort(struct Employee employees[], int numEmployees) {
    for (int i = 0; i < numEmployees - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < numEmployees; ++j) {
            if (strcmp(employees[j].name, employees[minIndex].name) < 0) {
                minIndex = j;
            }
        }

        // Swap the employees
        struct Employee temp = employees[i];
        employees[i] = employees[minIndex];
        employees[minIndex] = temp;
    }
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int numEmployees;

    readDataFromFile(employees, &numEmployees, "employee.txt");

    printf("Original employee names:\n");
    printEmployees(employees, numEmployees);

    printf("\nAfter Bubble Sort:\n");
    bubbleSort(employees, numEmployees);
    printEmployees(employees, numEmployees);

    printf("\nAfter Selection Sort:\n");
    selectionSort(employees, numEmployees);
    printEmployees(employees, numEmployees);

    return 0;
}
