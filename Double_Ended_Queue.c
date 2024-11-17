// A Double-Ended Queue (Deque) is a data structure that allows elements to be added or removed from both ends (front and rear). 

//Unlike a standard queue where elements are added at the rear and removed from the front (FIFO), a deque supports both FIFO and LIFO operations.

#include <stdio.h>
#define MAX 5  // Maximum size of the deque

int deque[MAX];  // Array to hold deque elements
int front = -1, rear = -1;  // Initialize front and rear pointers

// Function to add an element at the front (insertFront)
void insertFront(int value) {
    if ((front == 0 && rear == MAX - 1) || front == rear + 1) {
        printf("Deque is full! Cannot insert at the front.\n");
    } else {
        if (front == -1) {  // Deque is empty
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;  // Wrap around to the last position
        } else {
            front--;  // Move front pointer backwards
        }
        deque[front] = value;
        printf("Inserted %d at the front.\n", value);
    }
}

// Function to add an element at the rear (insertRear)
void insertRear(int value) {
    if ((front == 0 && rear == MAX - 1) || front == rear + 1) {
        printf("Deque is full! Cannot insert at the rear.\n");
    } else {
        if (front == -1) {  // Deque is empty
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;  // Wrap around to the first position
        } else {
            rear++;  // Move rear pointer forward
        }
        deque[rear] = value;
        printf("Inserted %d at the rear.\n", value);
    }
}

// Function to remove an element from the front (deleteFront)
int deleteFront() {
    if (front == -1) {
        printf("Deque is empty! Nothing to delete from the front.\n");
        return -1;
    } else {
        int deletedValue = deque[front];
        if (front == rear) {  // Only one element
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;  // Wrap around to the first position
        } else {
            front++;
        }
        printf("Deleted %d from the front.\n", deletedValue);
        return deletedValue;
    }
}

// Function to remove an element from the rear (deleteRear)
int deleteRear() {
    if (front == -1) {
        printf("Deque is empty! Nothing to delete from the rear.\n");
        return -1;
    } else {
        int deletedValue = deque[rear];
        if (front == rear) {  // Only one element
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1;  // Wrap around to the last position
        } else {
            rear--;
        }
        printf("Deleted %d from the rear.\n", deletedValue);
        return deletedValue;
    }
}

// Function to display the current elements of the deque
void displayDeque() {
    if (front == -1) {
        printf("Deque is empty!\n");
    } else {
        printf("Deque: ");
        if (front <= rear) {
            for (int i = front; i <= rear; i++) {
                printf("%d ", deque[i]);
            }
        } else {
            for (int i = front; i < MAX; i++) {
                printf("%d ", deque[i]);
            }
            for (int i = 0; i <= rear; i++) {
                printf("%d ", deque[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                displayDeque();
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

/**
Explanation of Functions:

insertFront(int value): Inserts an element at the front of the deque.
If the deque is full, it won’t allow insertion.
It handles wrapping around when the front reaches the beginning of the array.

insertRear(int value): Inserts an element at the rear of the deque.
If the deque is full, it won’t allow insertion.
It handles wrapping around when the rear reaches the end of the array.

deleteFront(): Removes an element from the front of the deque.
It checks if the deque is empty and handles wrapping around when removing from the front.

deleteRear(): Removes an element from the rear of the deque.
It checks if the deque is empty and handles wrapping around when removing from the rear.

displayDeque(): Displays all the elements in the deque. It handles wrapping around for both front and rear pointers.

Example Output:
Choose an option:
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Display Deque
6. Exit
Enter your choice: 1
Enter value to insert at front: 10
Inserted 10 at the front.

Choose an option:
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Display Deque
6. Exit
Enter your choice: 2
Enter value to insert at rear: 20
Inserted 20 at the rear.

Choose an option:
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Display Deque
6. Exit
Enter your choice: 5
Deque: 10 20

Choose an option:
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Display Deque
6. Exit
Enter your choice: 3
Deleted 10 from the front.

Choose an option:
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Display Deque
6. Exit
Enter your choice: 5
Deque: 20

Real-World Analogy:
Imagine a line at a theme park where you can either join the line at the front (for quick service) or back (as a new arrival). Similarly, the deque allows insertion and deletion from both ends, which is useful in situations like maintaining a list of recent actions or handling sliding windows in algorithms.

*/
