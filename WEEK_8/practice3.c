#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* front=NULL;
struct node* rear=NULL;

void enqueue(int n){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=NULL;
    if(rear==NULL){
        front=rear=newnode;
        return;
    }

    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue(){
    struct node* temp=front;

    if(front==NULL){
        printf("The queue is empty\n");
        return;
    }
    printf("%d\t",front->data);
    front=front->next;
    free(temp);
}

int main(){
    enqueue(1);
    enqueue(2);
    dequeue();
}