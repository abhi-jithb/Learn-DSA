#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a stack structure to hold the characters
#define MAX 100 // Maximum size of the stack

struct Stack {
    char arr[MAX];   // Array to hold the characters
    int top;         // Points to the top of the stack
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1; // Set the top to -1 to indicate that the stack is empty
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++(stack->top)] = value; // Increment top and insert the value
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1; // Return -1 if the stack is empty
    }
    return stack->arr[(stack->top)--]; // Return the top value and decrement top
}

// Function to reverse a string using a stack
void reverseString(char* str) {
    struct Stack stack;
    initStack(&stack);  // Initialize the stack

    // Push all characters of the string onto the stack
    for (int i = 0; str[i] != '\0'; i++) {
        push(&stack, str[i]);
    }

    // Pop characters from the stack to reverse the string
    int i = 0;
    while (!isEmpty(&stack)) {
        str[i++] = pop(&stack); // Replace characters in the original string
    }
}

int main() {
    char str[MAX];
    
    // Input the string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character from the string if present
    str[strcspn(str, "\n")] = 0;
    
    // Reverse the string using the stack
    reverseString(str);

    // Output the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}
