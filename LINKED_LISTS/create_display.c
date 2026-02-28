#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node *head=NULL;

void create_display(){
    struct node *temp=NULL,*newnode=NULL;
    int choice=1;
    


    while(choice==1){
        
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data\n");
        scanf("%d",&newnode->data);
        newnode->next = NULL;

        if( head == NULL ){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }

        printf("Choose '1' if you to add more nodes else '0' to exit");
        scanf("%d",&choice);
    }

    temp=head;
    while(temp != NULL ){
        printf("%d \t",temp->data);
        temp=temp->next;
    }
    
    
}







int main(){

    create_display();
    return 0;
}