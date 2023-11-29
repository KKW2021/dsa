#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent city data
struct City {
    char name[50];
    int stdCode;
};

// Function to perform sentinel linear search
int sentinelLinearSearch(struct City *cities, int n, const char *target) {
    // Add sentinel element at the end
    strcpy(cities[n].name, target);

    int i = 0;
    while (strcmp(cities[i].name, target) != 0) {
        i++;
    }

    // Remove the sentinel element
    cities[n].name[0] = '\0';

    if (i < n) {
        return i; // Found the city, return its index
    } else {
        return -1; // City not found in the list
    }
}

int main() {
    const char *filename = "cities.txt";
    struct City *cities;
    int numCities;

    // Read city data from the file
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1; // Exit with an error code
    }

    fscanf(file, "%d", &numCities);

    cities = (struct City *)malloc((numCities + 1) * sizeof(struct City)); // +1 for sentinel

    if (cities == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1; // Exit with an error code
    }

    for (int i = 0; i < numCities; ++i) {
        fscanf(file, "%s %d", cities[i].name, &cities[i].stdCode);
    }

    fclose(file);

    // Accept a city name from the user
    char target[50];
    printf("Enter the name of the city: ");
    scanf("%s", target);

    // Perform sentinel linear search
    int index = sentinelLinearSearch(cities, numCities, target);

    if (index != -1) {
        printf("STD Code for %s: %d\n", target, cities[index].stdCode);
    } else {
        printf("City not in the list.\n");
    }

    // Free the memory allocated for the array of cities
    free(cities);

    return 0;
}
