#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an employee
struct Employee {
    int id;
    char name[50];
    float salary;
};

// Function to read employee data from the file
int readEmployeeData(const char *filename, struct Employee **employees) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1; // Return -1 to indicate an error
    }

    int numEmployees;
    fscanf(file, "%d", &numEmployees);

    *employees = (struct Employee *)malloc(numEmployees * sizeof(struct Employee));

    if (*employees == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return -1; // Return -1 to indicate an error
    }

    for (int i = 0; i < numEmployees; ++i) {
        fscanf(file, "%d %s %f", &(*employees)[i].id, (*employees)[i].name, &(*employees)[i].salary);
    }

    fclose(file);

    return numEmployees;
}

// Function to perform insertion sort on the array of employees based on names
void insertionSort(struct Employee *arr, int n) {
    int i, j;
    struct Employee key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && strcmp(arr[j].name, key.name) > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform selection sort on the array of employees based on names
void selectionSort(struct Employee *arr, int n) {
    int i, j, minIndex;
    struct Employee temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            if (strcmp(arr[j].name, arr[minIndex].name) < 0) {
                minIndex = j;
            }
        }

        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to display the sorted array of employees
void displaySortedData(struct Employee *arr, int n) {
    printf("Sorted Data (by Name):\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s %.2f\n", arr[i].id, arr[i].name, arr[i].salary);
    }
}

// Function to free the memory allocated for the array of employees
void freeEmployeeArray(struct Employee *arr) {
    free(arr);
}

int main() {
    const char *filename = "employee.txt";
    struct Employee *employees;
    int numEmployees;

    // Read employee data from the file
    numEmployees = readEmployeeData(filename, &employees);

    if (numEmployees == -1) {
        return 1; // Exit with an error code
    }

    // Perform insertion sort
    struct Employee *insertionSortedData = malloc(numEmployees * sizeof(struct Employee));
    memcpy(insertionSortedData, employees, numEmployees * sizeof(struct Employee));
    insertionSort(insertionSortedData, numEmployees);
    displaySortedData(insertionSortedData, numEmployees);
    free(insertionSortedData);

    // Perform selection sort
    struct Employee *selectionSortedData = malloc(numEmployees * sizeof(struct Employee));
    memcpy(selectionSortedData, employees, numEmployees * sizeof(struct Employee));
    selectionSort(selectionSortedData, numEmployees);
    displaySortedData(selectionSortedData, numEmployees);
    free(selectionSortedData);

    // Free the memory allocated for the array of employees
    freeEmployeeArray(employees);

    return 0;
}
