#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 20

struct node{
    int id;
    char name[100];
};

struct node queue[max];
int front= -1;
int rear = -1;

void enqueue(struct node t){
    if(rear==max-1){
        printf("\nThe queue is full \n");
        return;
    }
    if(front==-1) front = 0 ;
    queue[++rear]=t;
    printf("\nEnqueued id : %d name : %s\n",t.id,t.name);
}

void dequeue(){
    if(front== -1 || front>rear){
        printf("\nThe queue is empty \n");
        return;
    }

    printf("\nDequeued %d %s",queue[front].id,queue[front].name);
    front=front+1;
    
}

int main(){
    int choice =1;
    int id;
    char name[100];
    struct node t;

    while(choice){

        

        if(choice==1){
            printf("\nEnter the name of the employee : ");
            scanf(" %[^\n]", name);
            printf("\nEnter the id of the employee : ");
            scanf("%d",&id);

            strcpy(t.name,name);
            t.id=id;

            enqueue(t);
        }

        if(choice==2){
            dequeue();
        }

        if(choice==0){
            break;
        }

        printf("\nEnter 1 to continue or 2 to dequeue and 0 to stop : ");
        scanf("%d",&choice);
        

    }
}