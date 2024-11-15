#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;             // Data stored in the node
    struct Node* next;    // Pointer to the next node
};

// Function to push an element onto the stack
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = value;       // Store value in the new node
    newNode->next = *top;        // Link the new node to the current top
    *top = newNode;              // Update top to the new node
    printf("Pushed %d onto the stack\n", value);
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *top;    // Temporary pointer to the top node
    int poppedValue = temp->data;// Save the data to return
    *top = (*top)->next;         // Update the top to the next node
    free(temp);                  // Free the memory of the popped node
    return poppedValue;
}

// Function to display the stack
void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* top = NULL; // Initialize an empty stack

    int choice, value;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display Stack\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 2:
                value = pop(&top);
                if (value != -1)
                    printf("Popped %d from the stack\n", value);
                break;
            case 3:
                displayStack(top);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
