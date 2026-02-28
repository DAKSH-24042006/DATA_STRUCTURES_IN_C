#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial
struct Node {
    int coeff;
    int expo;
    struct Node *next;
    struct Node *prev;
};

// Function to create a new node
struct Node* createNode(int coeff, int expo) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert node at end (descending order is maintained by user input)
void insertEnd(struct Node** head, int coeff, int expo) {
    struct Node* newNode = createNode(coeff, expo);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display polynomial
void display(struct Node* head) {
    if (head == NULL) {
        printf("0");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->expo);
        if (temp->next != NULL && temp->next->coeff >= 0)
            printf(" + ");
        else if (temp->next != NULL)
            printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

// Add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* p1 = poly1;
    struct Node* p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->expo == p2->expo) {
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0) // skip zero terms
                insertEnd(&result, sumCoeff, p1->expo);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->expo > p2->expo) {
            insertEnd(&result, p1->coeff, p1->expo);
            p1 = p1->next;
        }
        else {
            insertEnd(&result, p2->coeff, p2->expo);
            p2 = p2->next;
        }
    }

    // Remaining terms
    while (p1 != NULL) {
        insertEnd(&result, p1->coeff, p1->expo);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertEnd(&result, p2->coeff, p2->expo);
        p2 = p2->next;
    }

    return result;
}

// Main function
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;

    int n, coeff, expo;

    // Input first polynomial
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    printf("Enter terms in descending order of exponentls:\n");
    for (int i = 0; i < n; i++) {
        printf("Coefficient and exponent: ");
        scanf("%d %d", &coeff, &expo);
        insertEnd(&poly1, coeff, expo);
    }

    // Input second polynomial
    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &n);
    printf("Enter terms in descending order of exponents:\n");
    for (int i = 0; i < n; i++) {
        printf("Coefficient and exponent: ");
        scanf("%d %d", &coeff, &expo);
        insertEnd(&poly2, coeff, expo);
    }

    // Add polynomials
    sum = addPolynomials(poly1, poly2);

    // Display results
    printf("\nFirst Polynomial: ");
    display(poly1);
    printf("Second Polynomial: ");
    display(poly2);
    printf("Sum Polynomial: ");
    display(sum);

    return 0;
}
