#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100  // Maximum size of the stack

// Stack structure
char stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = c;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

// Function to get precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else {
        return 0;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char current = infix[i];

        // If the current character is an operand, add it to the postfix expression
        if (isalnum(current)) {
            postfix[j++] = current;
        }
        // If the current character is '(', push it onto the stack
        else if (current == '(') {
            push(current);
        }
        // If the current character is ')', pop from the stack until '(' is encountered
        else if (current == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  // Pop '('
        }
        // If the current character is an operator, pop from the stack based on precedence
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(current)) {
                postfix[j++] = pop();
            }
            push(current);
        }
        i++;
    }

    // Pop any remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';  // Null terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    // Get input from the user
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    // Display the result
    printf("Postfix expression: %s\n", postfix);

    return 0;
}


/**
OUTPUT
Enter an infix expression: A+B*(C-D)
Postfix expression: ABCD-*+ 
**/
