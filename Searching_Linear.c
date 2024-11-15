#include <stdio.h>

int findBook(int shelf[], int numberOfBooks, int bookToFind) {
    for (int position = 0; position < numberOfBooks; position++) {
        if (shelf[position] == bookToFind) {
            return position;  // Book found, return its position
        }
    }
    return -1;  // Book not found
}

int main() {
    int shelf[] = {101, 203, 305, 402, 555};  // List of books by their IDs
    int numberOfBooks = sizeof(shelf) / sizeof(shelf[0]);
    int bookToFind = 402;

    int foundPosition = findBook(shelf, numberOfBooks, bookToFind);

    if (foundPosition != -1) {
        printf("Book with ID %d found at position %d on the shelf.\n", bookToFind, foundPosition);
    } else {
        printf("Book with ID %d not found on the shelf.\n", bookToFind);
    }

    return 0;
}

/**
Explanation of Variables:
shelf[]: Represents a shelf containing books, where each book has a unique ID.
numberOfBooks: The total number of books on the shelf.
bookToFind: The ID of the book you are searching for on the shelf.
position: Used to go through each position on the shelf to see if it matches the book ID you're looking for.
foundPosition: Holds the result. If the book is found, it stores the position; otherwise, it’s set to -1.
**/
