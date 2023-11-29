#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Stack structure
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to initialize a stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Function to copy the contents of one stack into another
void copyStack(struct Stack* source, struct Stack* destination) {
    struct Stack temp;
    initialize(&temp);

    while (!isEmpty(source)) {
        push(&temp, pop(source));
    }

    while (!isEmpty(&temp)) {
        int element = pop(&temp);
        push(destination, element);
        push(source, element);
    }
}

// Function to print the elements of a stack
void printStack(struct Stack* stack) {
    for (int i = 0; i <= stack->top; ++i) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

// Main function
int main() {
    struct Stack stack1, stack2;
    initialize(&stack1);
    initialize(&stack2);

    // Push elements onto the original stack (stack1)
    push(&stack1, 1);
    push(&stack1, 2);
    push(&stack1, 3);
    push(&stack1, 4);

    printf("Original Stack:\n");
    printStack(&stack1);

    // Copy the contents of stack1 to stack2
    copyStack(&stack1, &stack2);

    printf("Copied Stack:\n");
    printStack(&stack2);

    return 0;
}
