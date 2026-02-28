#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Patient {
    char name[20];
    int age;
    int priority;
    struct Patient *next;
} Patient;

Patient *front = NULL, *rear = NULL;

void enqueue(char *name, int age, int priority) {
    Patient *newNode = malloc(sizeof(Patient));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->priority = priority;
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
        printf("No patients in queue!\n");
        return;
    }
    Patient *temp = front;
    printf("Serving: %s (Age %d, Priority %d)\n", temp->name, temp->age, temp->priority);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

int main() {
    enqueue("Alice", 30, 2);
    enqueue("Bob", 45, 1);
    dequeue();
    dequeue();
    return 0;
}
