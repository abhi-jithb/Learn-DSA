#include <stdio.h>

int findBook(int sortedShelf[], int left, int right, int bookToFind) {
    while (left <= right) {
        int middle = left + (right - left) / 2;  // Find the middle position

        if (sortedShelf[middle] == bookToFind) {
            return middle;  // Book found at the middle position
        }
        
        if (sortedShelf[middle] < bookToFind) {
            left = middle + 1;  // Search in the right half
        } else {
            right = middle - 1;  // Search in the left half
        }
    }
    return -1;  // Book not found
}

int main() {
    int sortedShelf[] = {101, 203, 305, 402, 555};  // Sorted list of books by their IDs
    int numberOfBooks = sizeof(sortedShelf) / sizeof(sortedShelf[0]);
    int bookToFind = 402;

    int foundPosition = findBook(sortedShelf, 0, numberOfBooks - 1, bookToFind);

    if (foundPosition != -1) {
        printf("Book with ID %d found at position %d on the sorted shelf.\n", bookToFind, foundPosition);
    } else {
        printf("Book with ID %d not found on the sorted shelf.\n", bookToFind);
    }

    return 0;
}
/**
Explanation of Variables:
sortedShelf[]: A sorted array representing books arranged by their IDs on the shelf.
left and right: Indicate the range of positions in the shelf to search, starting with the full range.
middle: The midpoint in the current range, used to divide the search space.
bookToFind: The ID of the book you're looking for on the sorted shelf.
foundPosition: Stores the position if the book is found; otherwise, it’s set to -1.


How Binary Search Works in This Code:
Start by setting left at the beginning and right at the end of the sorted shelf.
Find the middle position of the current range.
If the book ID at middle matches bookToFind, you’ve found the book.
If bookToFind is greater than the book ID at middle, update left to search the right half.
If bookToFind is less than the book ID at middle, update right to search the left half.
Repeat until the book is found or the range is empty (when left is greater than right).
**/
