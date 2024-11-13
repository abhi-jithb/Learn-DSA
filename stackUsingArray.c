#include <stdio.h>
#define MAX 5  // Maximum number of plates in the stack

int stack[MAX];  // Array to hold stack elements
int top = -1;    // Initialize top to -1, meaning the stack is empty

// Function to add a plate (push) onto the stack
void push(int plate) {
    if (top == MAX - 1) {
        printf("Stack is full! Cannot push plate %d\n", plate);
    } else {
        top++;
        stack[top] = plate;
        printf("Pushed plate %d onto the stack\n", plate);
    }
}

// Function to remove a plate (pop) from the stack
int pop() {
    if (top == -1) {
        printf("Stack is empty! Nothing to pop.\n");
        return -1;
    } else {
        int poppedPlate = stack[top];
        top--;
        printf("Popped plate %d from the stack\n", poppedPlate);
        return poppedPlate;
    }
}

// Function to view the plate at the top of the stack
int peek() {
    if (top == -1) {
        printf("Stack is empty! No plate at the top.\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to display the entire stack
void displayStack() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, plate;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Show Top (Peek)\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter plate ID to push: ");
                scanf("%d", &plate);
                push(plate);
                break;
            case 2:
                pop();
                break;
            case 3:
                plate = peek();
                if (plate != -1) {
                    printf("Top plate is: %d\n", plate);
                }
                break;
            case 4:
                displayStack();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

/**
Explanation of Functions:
push(int plate): Adds a new plate to the top of the stack if it's not full. If full, it displays an error message.
pop(): Removes and returns the plate at the top of the stack if it's not empty. If empty, it displays an error message.
peek(): Returns the plate at the top without removing it. If the stack is empty, it shows an error message.
isEmpty(): Returns 1 if the stack is empty, otherwise 0.
isFull(): Returns 1 if the stack is full, otherwise 0.

Output:
Choose an option:
1. Push
2. Pop
3. Show Top (Peek)
4. Display Stack
5. Exit
Enter your choice: 1
Enter plate ID to push: 101
Pushed plate 101 onto the stack

Choose an option:
1. Push
2. Pop
3. Show Top (Peek)
4. Display Stack
5. Exit
Enter your choice: 4
Stack: 101 

Choose an option:
1. Push
2. Pop
3. Show Top (Peek)
4. Display Stack
5. Exit
Enter your choice: 2
Popped plate 101 from the stack

Choose an option:
1. Push
2. Pop
3. Show Top (Peek)
4. Display Stack
5. Exit
Enter your choice: 5
Exiting program.



Real-World Analogy:
Imagine stacking plates on a shelf: you can only add or remove the plate on top. If the stack is full, you can't add another plate without removing one first. 
Similarly, you can only look at or remove the plate on top, following the Last-In-First-Out (LIFO) principle. This is how a stack works!

**/
