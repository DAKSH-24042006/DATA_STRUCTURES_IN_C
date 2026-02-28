#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int age;
    int priority;
    char name[100];
    struct node* next;
};

struct node* front=NULL;
struct node* rear=NULL;

void enqueue(int age,int priority,char name[]){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->age=age;
    strcpy(newnode->name,name);
    newnode->priority=priority;
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
    if(front==NULL){
        printf("The queue is empty\n");
        return;
    }

    struct node* temp=front;
    
    printf("\nDEQUEUEING\n");
    printf("%d %d %s",front->priority,front->age,front->name );
    front=front->next;
    free(temp);
}

int main(){
    enqueue(12,1,"Daksh");
    enqueue(30,12,"kuamr");
    dequeue();
    dequeue();
}