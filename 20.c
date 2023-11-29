#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure for a node in the circular list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append n integers to the circular list
void append(struct Node **last, int n, int random) {
    for (int i = 0; i < n; ++i) {
        int data = random ? rand() % 100 : 0;

        struct Node *newNode = createNode(data);

        // If the list is empty, set the new node as the first and last node
        if (*last == NULL) {
            *last = newNode;
            newNode->next = newNode;
        } else {
            // Append the new node at the end of the list
            newNode->next = (*last)->next;
            (*last)->next = newNode;
            *last = newNode;
        }
    }
}

// Function to display the circular list
void displayList(struct Node *last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = last->next;

    printf("Circular List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != last->next);
    printf("\n");
}

// Function to free the memory allocated for the circular list
void freeList(struct Node **last) {
    if (*last == NULL) {
        return;
    }

    struct Node *current = (*last)->next;
    struct Node *temp;

    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != (*last)->next);

    free(*last);
    *last = NULL;
}

int main() {
    struct Node *last = NULL;
    int n, random;

    // Seed the random number generator
    srand(time(NULL));

    // Accept input from the user
    printf("Enter the number of integers to append: ");
    scanf("%d", &n);

    // Validate the value of n
    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer for the number of integers.\n");
        return 1; // Exit with an error code
    }

    // Accept input for random generation
    printf("Do you want to generate random integers? (1 for yes, 0 for no): ");
    scanf("%d", &random);

    // Append n integers to the circular list
    append(&last, n, random);

    // Display the circular list
    displayList(last);

    // Free the allocated memory
    freeList(&last);

    return 0;
}
