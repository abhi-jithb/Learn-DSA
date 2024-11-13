// Bubble sort works like "bubbling up" the largest item to the end of a list, similar to repeatedly swapping books on a desk until the largest book moves to the far right. 

#include <stdio.h>

void sortBooks(int books[], int numberOfBooks) {
    for (int pass = 0; pass < numberOfBooks - 1; pass++) {
        for (int i = 0; i < numberOfBooks - pass - 1; i++) {
            if (books[i] > books[i + 1]) {
                // Swap if the current book is larger than the next book
                int temp = books[i];
                books[i] = books[i + 1];
                books[i + 1] = temp;
            }
        }
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
books[]: Array representing book IDs, initially unsorted.
numberOfBooks: Total number of books in the array.
pass: Tracks the current pass through the list, as bubble sort needs multiple passes.
i: The index in the list for the current book being compared.
temp: Temporary variable used to swap two book positions.

How Bubble Sort Works in This Code:
Each pass through the list pushes the largest book to the end, like bubbles rising to the top.
On each pass, compare adjacent books (books[i] and books[i + 1]).
If a book is larger than the next book, swap them so the larger book moves to the right.
Repeat for multiple passes until no more swaps are needed, which means the list is sorted.

Example Output:
With the initial list {305, 101, 402, 555, 203}, the output will be:
Books before sorting: 305 101 402 555 203 
Books after sorting: 101 203 305 402 555

Real-World Analogy:
Think of bubble sort as organizing a stack of books on your desk by repeatedly comparing two books at a time. 
Each pass through the books "bubbles up" the largest book to the end. 
After a few passes, the largest books are at the far right, and each new pass sorts the smaller unsorted books until everything is in order.


**/
