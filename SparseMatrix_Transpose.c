#include <stdio.h>

#define MAX 10  // Maximum number of non-zero elements (change this based on your needs)

// Function to input the sparse matrix and store non-zero elements in tuple form
void inputSparseMatrix(int matrix[][MAX], int *rows, int *cols) {
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", rows, cols);

    // Initializing matrix to 0
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            matrix[i][j] = 0;
        }
    }

    int nonZeroElements;
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &nonZeroElements);

    printf("Enter the non-zero elements in the format (row column value):\n");
    for (int i = 0; i < nonZeroElements; i++) {
        int r, c, value;
        scanf("%d %d %d", &r, &c, &value);
        matrix[r-1][c-1] = value;  // Store value at (r, c) (1-based index converted to 0-based)
    }
}

// Function to print the sparse matrix in tuple form
void printSparseMatrix(int matrix[][MAX], int rows, int cols) {
    printf("Tuple Representation of Sparse Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                printf("(%d, %d, %d)\n", i + 1, j + 1, matrix[i][j]);  // 1-based index
            }
        }
    }
}

// Function to transpose a sparse matrix
void transposeSparseMatrix(int matrix[][MAX], int rows, int cols) {
    printf("\nTuple Representation of Transposed Matrix:\n");
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] != 0) {
                printf("(%d, %d, %d)\n", j + 1, i + 1, matrix[i][j]);  // 1-based index
            }
        }
    }
}

int main() {
    int sparseMatrix[MAX][MAX];  // Matrix to store values
    int rows, cols;

    // Input the sparse matrix from the user
    inputSparseMatrix(sparseMatrix, &rows, &cols);
    
    // Print the original matrix in tuple form
    printSparseMatrix(sparseMatrix, rows, cols);
    
    // Print the transposed matrix in tuple form
    transposeSparseMatrix(sparseMatrix, rows, cols);

    return 0;
}
