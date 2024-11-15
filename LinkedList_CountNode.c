#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;             // Data in the node
    struct Node* next;    // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to count the number of nodes
int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;          // Increment the count for each node
        head = head->next; // Move to the next node
    }
    return count;
}

// Function to display the linked list
void displayList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int n, value;

    // Get the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Loop to get node values from the user
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        struct Node* newNode = createNode(value);

        if (head == NULL) {
            // If it's the first node, make it the head
            head = newNode;
        } else {
            // If it's not the first node, link it to the previous node
            temp->next = newNode;
        }

        temp = newNode; // Update temp to point to the last node
    }

    // Display the linked list
    displayList(head);

    // Count the nodes and display the count
    int nodeCount = countNodes(head);
    printf("Total number of nodes: %d\n", nodeCount);

    return 0;
}
