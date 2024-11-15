#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Size of the queue

// Declare an array for the queue, and two variables for the front and rear indices
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value) {
    // Check if the queue is full
    if ((rear + 1) % MAX == front) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
    } else {
        if (front == -1) {
            front = 0;  // If queue is empty, set front to 0
        }
        rear = (rear + 1) % MAX;  // Circular increment of rear
        queue[rear] = value;
        printf("%d enqueued to queue.\n", value);
    }
}

void dequeue() {
    // Check if the queue is empty
    if (front == -1) {
        printf("Queue is empty! Cannot dequeue.\n");
    } else {
        printf("%d dequeued from queue.\n", queue[front]);
        if (front == rear) {
            front = rear = -1;  // If the queue is empty after dequeue
        } else {
            front = (front + 1) % MAX;  // Circular increment of front
        }
    }
}

void display() {
    // Check if the queue is empty
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[rear]);  // Print the last element (rear)
    }
}

int main() {
    int choice, value;

    // Menu-driven program to perform enqueue, dequeue, and display operations
    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
