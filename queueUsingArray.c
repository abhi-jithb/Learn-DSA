#include <stdio.h>
#define MAX 5  // Maximum number of elements in the queue

int queue[MAX];  // Array to hold the queue elements
int front = -1, rear = -1;  // Initialize front and rear pointers

// Function to add an element to the queue (enqueue)
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is full! Cannot enqueue %d\n", value);
    } else {
        if (front == -1) {
            front = 0;  // First element in the queue
        }
        rear++;
        queue[rear] = value;
        printf("Enqueued %d into the queue\n", value);
    }
}

// Function to remove an element from the queue (dequeue)
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty! Nothing to dequeue.\n");
        return -1;
    } else {
        int dequeuedValue = queue[front];
        front++;
        printf("Dequeued %d from the queue\n", dequeuedValue);
        return dequeuedValue;
    }
}

// Function to view the element at the front of the queue
int peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty! No element at the front.\n");
        return -1;
    } else {
        return queue[front];
    }
}

// Function to display the elements of the queue
void displayQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Show Front (Peek)\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
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
                value = peek();
                if (value != -1) {
                    printf("Front element is: %d\n", value);
                }
                break;
            case 4:
                displayQueue();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

/
Explanation of Functions:
enqueue(int value): Adds an element to the queue if it’s not full. If the queue is empty (i.e., front == -1), it initializes the front to 0.
dequeue(): Removes the front element from the queue and shifts the front pointer. If the queue is empty, it prints an error message.
peek(): Displays the element at the front of the queue without removing it.
displayQueue(): Displays all the elements in the queue from front to rear.
Main Loop: Continuously prompts the user to choose between enqueueing, dequeueing, checking the front element, displaying the queue, or exiting.


Example Output:
Choose an option:
1. Enqueue
2. Dequeue
3. Show Front (Peek)
4. Display Queue
5. Exit
Enter your choice: 1
Enter value to enqueue: 10
Enqueued 10 into the queue

Choose an option:
1. Enqueue
2. Dequeue
3. Show Front (Peek)
4. Display Queue
5. Exit
Enter your choice: 1
Enter value to enqueue: 20
Enqueued 20 into the queue

Choose an option:
1. Enqueue
2. Dequeue
3. Show Front (Peek)
4. Display Queue
5. Exit
Enter your choice: 4
Queue: 10 20 

Choose an option:
1. Enqueue
2. Dequeue
3. Show Front (Peek)
4. Display Queue
5. Exit
Enter your choice: 2
Dequeued 10 from the queue

Choose an option:
1. Enqueue
2. Dequeue
3. Show Front (Peek)
4. Display Queue
5. Exit
Enter your choice: 4
Queue: 20   

Real-World Analogy:
Imagine a line of people waiting to buy tickets at a counter. 
The first person in line (front of the queue) will be served first. 
When new people arrive, they go to the end of the line (rear of the queue).
As people are served (dequeued), the front of the line moves forward. 
The process of adding and removing people from the queue follows this FIFO (First In, First Out) rule.

/
