#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the structure for the stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Function to initialize a stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if a stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if a stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

// Function to copy the contents of one stack to another
void copyStack(struct Stack *source, struct Stack *destination) {
    struct Stack tempStack;
    initialize(&tempStack);

    // Copy elements from source to tempStack while preserving order
    while (!isEmpty(source)) {
        push(&tempStack, pop(source));
    }

    // Copy elements from tempStack to destination and source to preserve order
    while (!isEmpty(&tempStack)) {
        int element = pop(&tempStack);
        push(destination, element);
        push(source, element);
    }
}

// Function to display the contents of a stack
void displayStack(struct Stack *stack) {
    printf("Stack: ");
    for (int i = 0; i <= stack->top; ++i) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack1, stack2;

    // Initialize the stacks
    initialize(&stack1);
    initialize(&stack2);

    // Push elements onto the first stack
    push(&stack1, 1);
    push(&stack1, 2);
    push(&stack1, 3);
    push(&stack1, 4);

    // Display the original stacks
    printf("Original Stacks:\n");
    printf("Stack 1: ");
    displayStack(&stack1);
    printf("Stack 2: ");
    displayStack(&stack2);

    // Copy the contents of stack1 to stack2
    copyStack(&stack1, &stack2);

    // Display the modified stacks
    printf("\nAfter copying:\n");
    printf("Stack 1: ");
    displayStack(&stack1);
    printf("Stack 2: ");
    displayStack(&stack2);

    return 0;
}
