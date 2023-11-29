#include <stdio.h>
#include <stdlib.h>

struct Employee {
    char name[50];
    int age;
    float salary;
};

void countingSort(struct Employee *arr, int n) {
    // Implement counting sort based on age
    // ...

    // Example: (Replace this with actual counting sort implementation)
    printf("Counting Sort\n");
}

void mergeSort(struct Employee *arr, int l, int r) {
    // Implement merge sort based on age
    // ...

    // Example: (Replace this with actual merge sort implementation)
    printf("Merge Sort\n");
}

void quickSort(struct Employee *arr, int low, int high) {
    // Implement quick sort based on age
    // ...

    // Example: (Replace this with actual quick sort implementation)
    printf("Quick Sort\n");
}

void writeSortedData(const char *filename, struct Employee *arr, int n) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d\n", n);

    for (int i = 0; i < n; ++i) {
        fprintf(file, "%s %d %.2f\n", arr[i].name, arr[i].age, arr[i].salary);
    }

    fclose(file);
}

int main() {
    const char *inputFilename = "employee.txt";
    const char *outputFilename = "sortedemponage.txt";
    struct Employee *employees;
    int numEmployees;

    // Read employee data from the file
    // ...

    // Example: (Replace this with actual reading of data)
    printf("Reading data from employee.txt\n");

    // Sort based on age using Counting Sort
    countingSort(employees, numEmployees);

    // Sort based on age using Merge Sort
    mergeSort(employees, 0, numEmployees - 1);

    // Sort based on age using Quick Sort
    quickSort(employees, 0, numEmployees - 1);

    // Write sorted data to 'sortedemponage.txt'
    writeSortedData(outputFilename, employees, numEmployees);

    // Free the allocated memory
    free(employees);

    printf("Sorting based on age completed. Sorted data written to 'sortedemponage.txt'\n");

    return 0;
}
