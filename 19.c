#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node *prev;
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node in the ordered doubly linked list
void insertNode(struct Node **head, int data, int ascending) {
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *current = *head;

    // Insert in ascending order
    if (ascending) {
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
    } 
    // Insert in descending order
    else {
        while (current->next != NULL && current->next->data > data) {
            current = current->next;
        }
    }

    // Adjust pointers to insert the new node
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

// Function to search for a data element in the doubly linked list
struct Node *searchNode(struct Node *head, int data, int ascending) {
    struct Node *current = head;

    // Search in ascending order
    if (ascending) {
        while (current != NULL && current->data < data) {
            current = current->next;
        }
    } 
    // Search in descending order
    else {
        while (current != NULL && current->data > data) {
            current = current->next;
        }
    }

    return current;
}

// Function to display the doubly linked list
void displayList(struct Node *head, int ascending) {
    printf("List (");
    if (ascending) {
        printf("Ascending");
    } else {
        printf("Descending");
    }
    printf("): ");

    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the doubly linked list
void freeList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node *head = NULL;

    // Insert elements in ascending order
    insertNode(&head, 10, 1);
    insertNode(&head, 20, 1);
    insertNode(&head, 15, 1);
    insertNode(&head, 25, 1);

    // Display the list in ascending order
    displayList(head, 1);

    // Search for an element in ascending order
    int searchData = 15;
    struct Node *searchResult = searchNode(head, searchData, 1);

    if (searchResult != NULL) {
        printf("Element %d found in the list.\n", searchData);
    } else {
        printf("Element %d not found in the list.\n", searchData);
    }

    // Insert elements in descending order
    insertNode(&head, 5, 0);
    insertNode(&head, 18, 0);
    insertNode(&head, 12, 0);
    insertNode(&head, 8, 0);

    // Display the list in descending order
    displayList(head, 0);

    // Search for an element in descending order
    searchData = 12;
    searchResult = searchNode(head, searchData, 0);

    if (searchResult != NULL) {
        printf("Element %d found in the list.\n", searchData);
    } else {
        printf("Element %d not found in the list.\n", searchData);
    }

    // Free the allocated memory
    freeList(head);

    return 0;
}
