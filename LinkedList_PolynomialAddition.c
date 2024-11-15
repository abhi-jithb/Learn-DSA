#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int coeff;      // Coefficient of the term
    int exp;        // Exponent of the term
    struct Node *next; // Pointer to the next term
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new term at the end of the linked list
void insertTerm(struct Node** poly, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node *result = NULL;  // Resultant polynomial
    struct Node *temp1 = poly1, *temp2 = poly2;

    // Traverse both polynomials and add corresponding terms
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp == temp2->exp) { // Same exponent, add coefficients
            insertTerm(&result, temp1->coeff + temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->exp > temp2->exp) { // poly1 term has higher exponent
            insertTerm(&result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else { // poly2 term has higher exponent
            insertTerm(&result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    }

    // If there are remaining terms in poly1
    while (temp1 != NULL) {
        insertTerm(&result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    // If there are remaining terms in poly2
    while (temp2 != NULL) {
        insertTerm(&result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

// Function to display the polynomial
void displayPolynomial(struct Node* poly) {
    struct Node* temp = poly;
    while (temp != NULL) {
        if (temp->coeff != 0) {
            printf("%dx^%d", temp->coeff, temp->exp);
            if (temp->next != NULL && temp->next->coeff > 0) {
                printf(" + ");
            }
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;

    // Input the first polynomial
    printf("Enter the first polynomial (coefficient exponent). Enter -1 to end:\n");
    int coeff, exp;
    while (1) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        if (coeff == -1) break;
        insertTerm(&poly1, coeff, exp);
    }

    // Input the second polynomial
    printf("Enter the second polynomial (coefficient exponent). Enter -1 to end:\n");
    while (1) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        if (coeff == -1) break;
        insertTerm(&poly2, coeff, exp);
    }

    // Add the two polynomials
    result = addPolynomials(poly1, poly2);

    // Display the result
    printf("Sum of the polynomials is: ");
    displayPolynomial(result);

    return 0;
}

/**
Output

Enter the first polynomial (coefficient exponent). Enter -1 to end:
Enter coefficient and exponent: 5 2
Enter coefficient and exponent: 4 1
Enter coefficient and exponent: 3 0
Enter coefficient and exponent: -1 -1

Enter the second polynomial (coefficient exponent). Enter -1 to end:
Enter coefficient and exponent: 4 2
Enter coefficient and exponent: -4 1
Enter coefficient and exponent: 2 0
Enter coefficient and exponent: -1 -1
**/
