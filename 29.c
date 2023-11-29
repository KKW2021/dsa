#include <stdio.h>
#include <stdlib.h>

// Node structure
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

// Function to append a new element to the circular list
void append(struct Node **last, int data) {
    struct Node *newNode = createNode(data);

    if (*last == NULL) {
        // If the list is empty, make the new node the only node in the list
        *last = newNode;
        (*last)->next = *last;
    } else {
        // Append the new node to the end of the circular list
        newNode->next = (*last)->next;
        (*last)->next = newNode;
        *last = newNode;
    }
}

// Function to display the elements of the circular list
void display(struct Node *last) {
    if (last == NULL) {
        printf("Circular list is empty.\n");
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

int main() {
    struct Node *last = NULL;
    int n, data;

    // Accept the number of integers from the user
    printf("Enter the number of integers to append: ");
    scanf("%d", &n);

    // Accept 'n' integers from the user and append them to the circular list
    for (int i = 0; i < n; ++i) {
        printf("Enter integer #%d: ", i + 1);
        scanf("%d", &data);
        append(&last, data);
    }

    // Display the circular list
    display(last);

    // Free the allocated memory (not done in this concise example for simplicity)

    return 0;
}
