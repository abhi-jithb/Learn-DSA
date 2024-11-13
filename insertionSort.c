#include <stdio.h>

void sortBooks(int books[], int numberOfBooks) {
    for (int currentBook = 1; currentBook < numberOfBooks; currentBook++) {
        int currentID = books[currentBook];  // The book we’re trying to place
        int previousBook = currentBook - 1;

        // Move books that are larger than currentID one position ahead
        while (previousBook >= 0 && books[previousBook] > currentID) {
            books[previousBook + 1] = books[previousBook];
            previousBook = previousBook - 1;
        }
        
        // Place the currentID book in its correct position
        books[previousBook + 1] = currentID;
    }
}

void displayBooks(int books[], int numberOfBooks) {
    for (int i = 0; i < numberOfBooks; i++) {
        printf("%d ", books[i]);
    }
    printf("\n");
}

int main() {
    int books[] = {305, 101, 402, 555, 203};  // IDs of books on a messy desk
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
books[]: Represents an array of book IDs that are initially in a messy, unsorted order.
numberOfBooks: The total number of books we need to sort.
currentBook: The position of the book currently being sorted.
currentID: The ID of the book we’re currently trying to place in the correct spot.
previousBook: Tracks the books we’ve already sorted to find the right position for the current book.


How Insertion Sort Works in This Code:
Start with the second book (currentBook = 1) because the first book is considered "already sorted."
Take the currentID of the current book and compare it with books that are already sorted.
Shift each book that is larger than currentID one position to the right.
Insert currentID in the correct position where all books before it are smaller.
Move to the next book and repeat until all books are sorted.

Example Output:
With the initial list {305, 101, 402, 555, 203}, the output will be:
Books before sorting: 305 101 402 555 203 
Books after sorting: 101 203 305 402 555

Real-World Analogy:
Imagine each book on a desk is disorganized, and you're picking one book at a time to place it correctly in a growing "sorted" section of the desk. 
This insertion process gradually builds up the sorted order, just like arranging books in ascending order based on their IDs. 
This analogy makes it easier to visualize how insertion sort works by organizing items one at a time.
**/
