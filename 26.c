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

// Function to insert a new element in ascending order
void insert(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    // Insert at the beginning if the list is empty or the new data is smaller than the head
    if (*head == NULL || data < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse the list to find the correct position for the new node
    struct Node *current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    // Insert the new node after the current node
    newNode->next = current->next;
    current->next = newNode;
}

// Function to search for an element in the list
struct Node *search(struct Node *head, int target) {
    struct Node *current = head;

    while (current != NULL && current->data < target) {
        current = current->next;
    }

    if (current != NULL && current->data == target) {
        return current;
    } else {
        return NULL; // Element not found
    }
}

// Function to display the elements of the list
void display(struct Node *head) {
    struct Node *current = head;

    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;

    // Insert elements in ascending order
    insert(&head, 20);
    insert(&head, 10);
    insert(&head, 30);
    insert(&head, 15);

    // Display the list
    display(head);

    // Search for an element
    int target = 15;
    struct Node *result = search(head, target);

    if (result != NULL) {
        printf("%d found in the list.\n", target);
    } else {
        printf("%d not found in the list.\n", target);
    }

    // Free the allocated memory (not done in this concise example for simplicity)
    
    return 0;
}
