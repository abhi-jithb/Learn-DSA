#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100  // Maximum size of the stack

// Stack structure
int stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = value;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char *exp) {
    int i = 0;
    while (exp[i] != '\0') {
        // If the current character is a number, push it onto the stack
        if (isdigit(exp[i])) {
            push(exp[i] - '0');  // Convert char to int and push
        }
        else {
            // The current character is an operator, pop two operands
            int operand2 = pop();
            int operand1 = pop();
            int result;

            // Apply the operator
            switch (exp[i]) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                default:
                    printf("Invalid operator!\n");
                    return -1;
            }

            // Push the result back onto the stack
            push(result);
        }
        i++;
    }

    // The result is the only element left in the stack
    return pop();
}

int main() {
    char exp[MAX];

    // Get input from the user
    printf("Enter a postfix expression: ");
    scanf("%s", exp);

    // Evaluate the postfix expression
    int result = evaluatePostfix(exp);

    // Print the result
    printf("Result of postfix evaluation: %d\n", result);

    return 0;
}
