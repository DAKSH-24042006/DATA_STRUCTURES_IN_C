#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;

void create_list(){
    struct node *temp,*newnode;
    int choice =1;
    temp=NULL;
    newnode=NULL;

    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data :");
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }

        printf("\nEnter 1 to continue and 0 to stop : ");
        scanf("%d",&choice);
    }
    
}

void display_list(){
    struct node *temp=head;
    printf("\nDisplaying the list :\n");
    while(temp != NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

void insert_before(int element,int key){
    struct node *temp,*newnode;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    
    newnode->data=element;
    newnode->next=NULL;

    while (temp->next->data!=key  && temp->next!=NULL){
            temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    
}

void insert_after(int element,int key){
    struct node *temp,*newnode;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    
    newnode->data=element;
    newnode->next=NULL;

    while ( temp!=NULL &&  temp->data!=key){
            temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    
}

void delete_specific(int key){
    struct node *curr,*prev;
    curr=head;
    prev=head;

    while (curr->data!=key){
        curr=curr->next;
    }
    while(prev->next->data!=key){
        prev=prev->next;
    }

    prev->next=curr->next;
    free(curr);
    
    


}

void sort_list(){
    struct node *i,*j;
    int temp;
    for(i=head;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data > j->data){
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
}

void delete_alternate(){
    struct node *temp=head;
    while(temp!=NULL && temp->next!=NULL){
        struct node *to_delete=temp->next;
        temp->next=to_delete->next;
        free(to_delete);
        temp=temp->next;
    }
}

int main(){
    printf("Creating a list :\n");
    create_list();
    int m;
    int n=1;
    
    while(n){
        printf("\nEnter 1 to display the list : ");
        printf("\nEnter 2 to insert an element before a specified element:");
        printf("\nEnter 3 to insert an element after a specified element:");
        printf("\nEnter 4 to delete an element :");
        printf("\nEnter 0 to to exit the list : \n");

        scanf("%d",&m);
        switch (m){
            case 1 :{
                display_list();
                break;
            }
            case 2 :{
                int key,element;
                printf("\nEnter the element to insert:");
                scanf("%d",&element);
                printf("\nEnter the element before which to be inserted:");
                scanf("%d",&key);
                insert_before(element,key);
                break;

            }

            case 3 :{
                int key,element;
                printf("\nEnter the element to insert:");
                scanf("%d",&element);
                printf("\nEnter the element after which to be inserted:");
                scanf("%d",&key);
                insert_after(element,key);
                break;

            }

            case 4 :{
                int key;
                printf("\nEnter the element to delete:");
                scanf("%d",&key);
                delete_specific(key);
                break;

            }
            case 0 :{
                printf("\nExit\n");
                exit(0);
            }
            default :{
                printf("\ninvalid choice\n");
            }
        }
        
        
        
    }
    
}