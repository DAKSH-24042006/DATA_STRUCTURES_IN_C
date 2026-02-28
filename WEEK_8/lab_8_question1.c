#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 5

struct node{
    int id;
    char name[20];
};

struct node queue[max];
int front=-1,rear=-1;

void enqueue(struct node t){

    if(rear == max-1){
        printf("The queue is full\n");
        return;
    }

    if(front == -1 )front=0;
    queue[++rear]=t;
    printf("\nENQUEUED %d , %s\n",t.id,t.name);

}

void dequeue(){
    if(front == -1 || front > rear){
        printf("\nTHE QUEUE IS EMPTY\n");
        return;
    }

    else{
        printf("The name is : %s and the id is %d",queue[front].name,queue[front].id);
        front++;
    }
}

int main()
{
    int choice =1;
    int id=1;
    struct node t;
    char name[20];

    while(choice){

        printf("\nEnter your choice '1' to enqueue and '2' to dequeue and 0 to stop : ");
        scanf("%d",&choice);

        if(choice==1){
            printf("\nEnter the name of the person : ");
            scanf("%s", name);
            strcpy(t.name,name);
            t.id=id++;

            enqueue(t);
        }
        else if(choice==2){
            dequeue();
        }
        else{
            break;
        }
    }

    return 0;
}
