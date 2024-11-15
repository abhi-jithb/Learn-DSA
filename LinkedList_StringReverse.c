#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
struct Node {
    char data;           // Character data
    struct Node* next;   // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a character to the linked list
void push(struct Node** head, char data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head; // Point the new node to the current head
    *head = newNode;       // Update the head to the new node
}

// Function to reverse the string and display it
void displayReversed(struct Node* head) {
    printf("Reversed string: ");
    while (head != NULL) {
        printf("%c", head->data); // Print character from the linked list
        head = head->next;        // Move to the next node
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL; // Initialize an empty linked list
    char input[100];          // String input buffer

    printf("Enter a string to reverse: ");
    scanf("%s", input);       // Get string input from user

    // Push each character of the string into the linked list
    for (int i = 0; i < strlen(input); i++) {
        push(&head, input[i]);
    }

    // Display the reversed string
    displayRe
