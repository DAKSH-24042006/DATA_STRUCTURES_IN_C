#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Dequeued: %d\n", front->data);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

int main() {
    enqueue(5);
    enqueue(10);
    dequeue();
    enqueue(15);
    return 0;
}

