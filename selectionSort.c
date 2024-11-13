// think of it like "picking the smallest book on a desk and placing it at the beginning," then moving to the next smallest and placing it in the next position, and so on.
#include <stdio.h>

void sortBooks(int books[], int numberOfBooks) {
    for (int currentPosition = 0; currentPosition < numberOfBooks - 1; currentPosition++) {
        int smallestPosition = currentPosition;  // Position of the smallest book

        // Find the smallest book in the unsorted section
        for (int nextBook = currentPosition + 1; nextBook < numberOfBooks; nextBook++) {
            if (books[nextBook] < books[smallestPosition]) {
                smallestPosition = nextBook;
            }
        }

        // Swap the smallest book found with the current book
        int temp = books[currentPosition];
        books[currentPosition] = books[smallestPosition];
        books[smallestPosition] = temp;
    }
}

void displayBooks(int books[], int numberOfBooks) {
    for (int i = 0; i < numberOfBooks; i++) {
        printf("%d ", books[i]);
    }
    printf("\n");
}

int main() {
    int books[] = {305, 101, 402, 555, 203};  // Unsorted list of books by their IDs
    int numberOfBooks = sizeof(books) / sizeof(books[0]);

    printf("Books before sorting: ");
    displayBooks(books, numberOfBooks);

    sortBooks(books, numberOfBooks);

    printf("Books after sorting: ");
    displayBooks(books, numberOfBooks);

    return 0;
}

/**
Explanation of Variables:
books[]: Represents an array of book IDs that are initially in an unsorted order.
numberOfBooks: The total number of books to be sorted.
currentPosition: The current index where we’re placing the next smallest book.
smallestPosition: Tracks the position of the smallest book in the unsorted portion of the list.
nextBook: Used to scan through the unsorted section to find the smallest book.
temp: A temporary variable used to swap the values when placing the smallest book at the current position.

How Selection Sort Works in This Code:
Start at the first position (currentPosition).
Find the smallest book in the remaining unsorted portion of the list by scanning from currentPosition to the end.
Once the smallest book is found, swap it with the book at currentPosition.
Move currentPosition one step forward and repeat until all books are sorted.

Example Output:
With the initial list {305, 101, 402, 555, 203}, the output will be:
Books before sorting: 305 101 402 555 203 
Books after sorting: 101 203 305 402 555

Real-World Analogy:
Think of it like organizing books on a desk by repeatedly picking the smallest one you can find and placing it at the beginning of the row.
This "selection" process goes through the entire desk each time, putting the smallest book in its correct spot, gradually building a sorted row from the smallest to the largest.
This analogy helps to visualize how selection sort "selects" the smallest item each time and organizes items step-by-step.

**/
