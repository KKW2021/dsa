#include <stdio.h>
#include <stdlib.h>

// Define the structure for a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term *next;
};

// Function to create a new term in the polynomial
struct Term *createTerm(int coefficient, int exponent) {
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into the polynomial
void insertTerm(struct Term **poly, int coefficient, int exponent) {
    struct Term *newTerm = createTerm(coefficient, exponent);

    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term *current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to display a polynomial
void displayPolynomial(struct Term *poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to multiply two polynomials
struct Term *multiplyPolynomials(struct Term *poly1, struct Term *poly2) {
    struct Term *result = NULL;

    // Multiply each term of poly1 with each term of poly2
    while (poly1 != NULL) {
        struct Term *tempPoly2 = poly2;
        while (tempPoly2 != NULL) {
            int coefficient = poly1->coefficient * tempPoly2->coefficient;
            int exponent = poly1->exponent + tempPoly2->exponent;

            // Insert the term into the result polynomial
            insertTerm(&result, coefficient, exponent);

            tempPoly2 = tempPoly2->next;
        }
        poly1 = poly1->next;
    }

    return result;
}

// Function to free the memory allocated for a polynomial
void freePolynomial(struct Term *poly) {
    struct Term *current = poly;
    while (current != NULL) {
        struct Term *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Term *poly1 = NULL;
    struct Term *poly2 = NULL;

    // Example polynomials: 2x^2 + 3x + 4 and 1x^1 + 2x^0
    insertTerm(&poly1, 2, 2);
    insertTerm(&poly1, 3, 1);
    insertTerm(&poly1, 4, 0);

    insertTerm(&poly2, 1, 1);
    insertTerm(&poly2, 2, 0);

    // Display the original polynomials
    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    // Multiply the polynomials
    struct Term *result = multiplyPolynomials(poly1, poly2);

    // Display the result
    printf("Result: ");
    displayPolynomial(result);

    // Free the allocated memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
