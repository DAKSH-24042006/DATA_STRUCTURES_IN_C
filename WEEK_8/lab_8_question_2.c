#include <stdio.h>
#include <stdlib.h>
#define max 5

int queue[max];
int front =-1 , rear=-1;

void enqueue(int n){
    if(front == (rear+1)%max ){
        printf("\nTHE QUEUE IS FULL\n");
        return;
    }
    if(front == -1)front=0;
    rear=(rear+1)%max;
    queue[rear]=n;
    printf("\nENQUEUED %d",n);
}

void dequeue(){
    if(front == -1){
        printf("\nTHE QUEUE IS EMPTY");
        return;
    }
    printf("\nDequeued: %d\n", queue[front]);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % max;
}

int main()
{

    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    enqueue(40);
    enqueue(50);
    enqueue(60);
    return 0;

}
