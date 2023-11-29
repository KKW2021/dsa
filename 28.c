#include <stdio.h>
#include <stdlib.h>

struct Employee {
    char name[50];
    int age;
    float salary;
};

// Merge Sort functions
void merge(struct Employee *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    struct Employee L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].age <= R[j].age) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct Employee *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Quick Sort functions
int partition(struct Employee *arr, int low, int high) {
    int pivot = arr[high].age;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].age <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            struct Employee temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i + 1] and arr[high] (pivot)
    struct Employee temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(struct Employee *arr, int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after the partitioning index
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to write sorted data to 'sortedemponage.txt'
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
    FILE *file = fopen(inputFilename, "r");

    if (file == NULL) {
        printf("Error opening file: %s\n", inputFilename);
        return 1; // Exit with an error code
    }

    fscanf(file, "%d", &numEmployees);

    employees = (struct Employee *)malloc(numEmployees * sizeof(struct Employee));

    if (employees == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1; // Exit with an error code
    }

    for (int i = 0; i < numEmployees; ++i) {
        fscanf(file, "%s %d %f", employees[i].name, &employees[i].age, &employees[i].salary);
    }

    fclose(file);

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
