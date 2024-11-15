#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;              // Data stored in the node
    struct Node* next;     // Pointer to the next node
};

// Queue structure
struct Queue {
    struct Node* front;    // Pointer to the front of the queue
    struct Node* rear;     // Pointer to the rear of the queue
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue (add) an element to the queue
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) { // If the queue is empty
        q->front = q->rear = newNode;
        printf("Enqueued: %d\n", value);
        return;
    }
    q->rear->next = newNode; // Link the new node to the end of the queue
    q->rear = newNode;       // Update the rear pointer
    printf("Enqueued: %d\n", value);
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue* q) {
    if (q->front == NULL) { // If the queue is empty
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    struct Node* temp = q->front; // Store the front node temporarily
    int dequeuedValue = temp->data;
    q->front = q->front->next;    // Move the front pointer to the next node
    if (q->front == NULL)         // If the queue becomes empty
        q->rear = NULL;
    free(temp);                   // Free the memory of the dequeued node
    return dequeuedValue;
}

// Function to display the queue
void displayQueue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main program
int main() {
    struct Queue* q = createQueue(); // Create an empty queue

    int choice, value;
    while (1) {
        printf("\n--- Queue Operations ---\n");
        printf("1. Enqueue (Add to queue)\n");
        printf("2. Dequeue (Remove from queue)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                break;
            case 3:
                displayQueue(q);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
