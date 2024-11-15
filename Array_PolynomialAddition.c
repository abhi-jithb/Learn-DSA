#include <stdio.h>

void addPolynomials(int poly1[], int poly2[], int result[], int n1, int n2) {
    // Find the larger degree (size of result array)
    int maxDegree = (n1 > n2) ? n1 : n2;

    // Add corresponding coefficients
    for (int i = 0; i < maxDegree; i++) {
        if (i < n1)
            result[i] += poly1[i];
        if (i < n2)
            result[i] += poly2[i];
    }
}

void printPolynomial(int poly[], int degree) {
    printf("Polynomial: ");
    for (int i = degree - 1; i >= 0; i--) {
        if (i == 0) {
            printf("%d", poly[i]);
        } else if (poly[i] != 0) {
            printf("%dx^%d + ", poly[i], i);
        }
    }
    printf("\n");
}

int main() {
    int n1, n2;

    // Input degree of the first polynomial
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &n1);
    int poly1[n1];
    
    // Input coefficients of the first polynomial
    printf("Enter coefficients of the first polynomial (from highest degree to constant):\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &poly1[i]);
    }

    // Input degree of the second polynomial
    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &n2);
    int poly2[n2];
    
    // Input coefficients of the second polynomial
    printf("Enter coefficients of the second polynomial (from highest degree to constant):\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &poly2[i]);
    }

    // Determine the size of the result polynomial
    int maxDegree = (n1 > n2) ? n1 : n2;
    int result[maxDegree];

    // Initialize result polynomial with zeros
    for (int i = 0; i < maxDegree; i++) {
        result[i] = 0;
    }

    // Add the polynomials
    addPolynomials(poly1, poly2, result, n1, n2);

    // Print the resulting polynomial
    printPolynomial(result, maxDegree);

    return 0;
}
