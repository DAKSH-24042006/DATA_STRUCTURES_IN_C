#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;

};

struct node *head=NULL;

void create_list(){
    struct node *temp,*newnode;
    int choice =1;

    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data :");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;

        if(head==NULL){
            temp=newnode;
            head=newnode;
        }
        else{
            newnode->prev=temp;
            temp->next=newnode;
            temp=newnode;
        }

        printf("\nEnter 1 to continue and 0 to stop :");
        scanf("%d",&choice);
    }
}

void display(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

void add_at_rear(int key){
    struct node *temp=head;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->next=NULL;
    newnode->prev=NULL;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=newnode;
    newnode->prev=temp;
    temp=newnode;
}

void delete_from_rear(){
    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}

void insert_at_pos(int pos,int element){
    struct node *temp,*newnode;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=element;
    newnode->next=NULL;
    newnode->prev=NULL;

    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }

    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;

}

void delete_at_pos(int pos){
    struct node *temp;
    temp=head;

    for(int i=1;i<pos;i++){
        temp=temp->next;
    }

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);

}




int main(){
    int n=1;
    int p;
    create_list();

    while(n){

        printf("\nEnter 1 to display list :");
        printf("\nEnter 2 to add at rear list :");
        printf("\nEnter 3 to delete at rear list :");
        printf("\nEnter 4 to insert at a pos :");
        printf("\nEnter 5 to delete from a pos :");
        printf("\nEnter 0 to exit :\n");

        scanf("%d",&p);

        switch(p){
            case 1 :{
                display();
                break;
            }

            case 2 :{
                int key;
                printf("\nEnter the no to add at the rear :");
                scanf("%d",&key);
                add_at_rear(key);
                break;

            }

            case 3 :{
                delete_from_rear();
                break;
            }

            case 4 :{
                int element,pos;
                printf("\nEnter the element to insert : ");
                scanf("%d",&element);
                printf("\nEnter the pos to be insert to :");
                scanf("%d",&pos);
                insert_at_pos(pos,element);
                break;
            }

            case 5 :{
                int pos;
                printf("\nEnter the pos to be deleted to :");
                scanf("%d",&pos);
                delete_at_pos(pos);
                break;
            }

            case 0 :{
                printf("\nExit");
                exit(0);
                
            }
            default:{
                printf("invalid");
            }
        }
    }
}
