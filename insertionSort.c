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
