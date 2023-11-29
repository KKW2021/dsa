#include <stdio.h>
#include <stdlib.h>

// Node structure representing each element in the linked list
struct Node {
    int data;           // Data of the node
    struct Node* next;  // Pointer to the next node in the linked list
};

// Function to swap data of two nodes
void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to perform selection sort on a linked list
void selectionSort(struct Node* start) {
    struct Node *i, *j;

    for (i = start; i != NULL; i = i->next) {
        struct Node* min_ptr = i;

        // Find the minimum element in the unsorted part of the list
        for (j = i->next; j != NULL; j = j->next) {
            if (j->data < min_ptr->data)
                min_ptr = j;
        }

        // Swap the found minimum element with the current element (i)
        swap(i, min_ptr);
    }
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    // If the linked list is empty, make the new node the head
    if (*head_ref
