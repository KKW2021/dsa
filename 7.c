#include <stdio.h>
#include <string.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Stack structure for characters
struct CharStack {
    char items[MAX_SIZE];
    int top;
};

// Function to initialize the character stack
void init(struct CharStack* stack) {
    stack->top = -1;
}

// Function to check if the character stack is empty
int isEmpty(struct CharStack* stack) {
    return stack->top == -1;
}

// Function to check if the character stack is full
int isFull(struct CharStack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push a character onto the character stack
void push(struct CharStack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Function to pop a character from the character stack
char pop(struct CharStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    struct CharStack stack;
    init(&stack);

    int length = strlen(str);

    // Push the first half of the string onto the stack
    for (int i = 0; i < length / 2; ++i) {
        push(&stack, str[i]);
    }

    // Pop and compare with the second half of the string
    int start = (length + 1) / 2;  // Start index for the second half
    for (int i = start; i < length; ++i) {
        char topChar = pop(&stack);
        if (topChar != str[i]) {
            return 0; // Not a palindrome
        }
    }

    return 1; // Palindrome
}

// Main function
int main() {
    char str[] = "radar";

    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}
