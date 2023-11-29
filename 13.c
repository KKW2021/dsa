#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to swap the data of two nodes
void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to perform bubble sort on the linked list
void bubbleSort(struct Node* start) {
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    // Check for empty list
    if (start == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    insertAtEnd(&head, 64);
    insertAtEnd(&head, 34);
    insertAtEnd(&head, 25);
    insertAtEnd(&head, 12);
    insertAtEnd(&head, 22);
    insertAtEnd(&head, 11);
    insertAtEnd(&head, 90);

    printf("Linked List before sorting:\n");
    printList(head);

    // Perform bubble sort on the linked list
    bubbleSort(head);

    printf("Linked List after sorting:\n");
    printList(head);

    return 0;
}
