#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *first = NULL, *last = NULL;

// Insert at end
void insertEnd(int value) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    if (first == NULL) {
        first = last = newnode;
        newnode->next = first; // circular
    } else {
        last->next = newnode;
        newnode->next = first;
        last = newnode;
    }
}

// Delete from beginning
void deleteBegin() {
    if (first == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = first;
    if (first == last) { // only one node
        first = last = NULL;
    } else {
        first = first->next;
        last->next = first;
    }
    free(temp);
}

// Delete from end
void deleteEnd() {
    if (first == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = first;
    if (first == last) { // only one node
        first = last = NULL;
        free(temp);
        return;
    }
    while (temp->next != last) {
        temp = temp->next;
    }
    temp->next = first;
    free(last);
    last = temp;
}

// Display list
void display() {
    if (first == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = first;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != first);
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Singly Linked List Menu ---\n");
        printf("1. Insert at end\n");
        printf("2. Delete from beginning\n");
        printf("3. Delete from end\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 2:
                deleteBegin();
                break;
            case 3:
                deleteEnd();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
