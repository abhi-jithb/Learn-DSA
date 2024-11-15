#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the circular queue

int front = -1, rear = -1;  // Initialize the front and rear pointers
int queue[MAX];  // Array to hold the queue elements

// Enqueue function (Add an element to the queue)
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {  // Check if the queue is full
        printf("Queue is full! Cannot enqueue %d.\n", value);
    } else {
        if (front == -1) {  // If the queue is empty, set front to 0
            front = 0;
        }
        rear = (rear + 1) % MAX;  // Circular increment
        queue[rear] = value;
        printf("Enqueued %d\n", value);
    }
}

// Dequeue function (Remove an element from the queue)
int dequeue() {
    if (front == -1) {  // Check if the queue is empty
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    } else {
        int item = queue[front];
        if (front == rear) {  // If there's only one element left, reset the queue
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;  // Circular increment
        }
        return item;
    }
}

// Display the queue elements
void display() {
    if (front == -1) {  // If the queue is empty
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int choice, value;

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
                value = dequeue();
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
