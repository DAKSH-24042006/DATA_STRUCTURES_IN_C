#include <stdio.h>
#include <stdlib.h>
 
struct node{
    int data;
    struct node * next;
    struct node * prev;
};

struct node * head =NULL;
struct node * tail=NULL;


void create_list(){
    struct node * newnode =NULL;
    int choice =1;

    while (choice){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the element \n");
        scanf("%d",&newnode->data);

        newnode->next=NULL;
        newnode->prev=NULL;

        if(head==NULL){
            head=newnode;
            tail=newnode;
        }

        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }

        printf("Choose '1' if you to add more nodes else '0' to exit");
        scanf("%d",&choice);


    }



}

void display(){
    struct node * temp=head;

    while( temp != NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    
}

void insert_rear(){
    struct node * newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element to insert\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;

    printf("adding element \n");
    newnode->prev=tail;
    tail->next=newnode;
    tail=newnode;
}

void delete_rear(){
    printf("\ndeleting from rear\n");
    struct node * temp;
    temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    free(temp);
}

void insert_at_given_pos(){
    struct node * newnode,* temp;
    temp=head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element to insert\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    int n;
    printf("Enter the pos\n");
    scanf("%d",&n);


    printf("adding element \n");
    for(int i=1;i<n-1;i++){
        temp=temp->next;
    }

    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;


}

void delete_at_pos(){
    struct node * temp;
    temp=head;
    
    int n;
    printf("Enter the pos to delete\n");
    scanf("%d",&n);


    printf("\ndeleting element \n");
    for(int i=1;i<n;i++){
        temp=temp->next;
    }

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);

}

void insert_after_node(){
    struct node * newnode,* temp;
    temp=head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element to insert\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    int n;
    printf("\nEnter the key value\n");
    scanf("%d",&n);

    while(temp->data != n ){
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;

}

void insert_before_node(){
    struct node * newnode,* temp;
    temp=head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element to insert\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    int n;
    printf("\nEnter the key value\n");
    scanf("%d",&n);

    while(temp->next->data != n ){
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;

}

void display_tail(){
    struct node * temp=tail;

    while( temp != NULL){
        printf("%d\t",temp->data);
        temp=temp->prev;
    }
    
}

int main(){
    int choice;

    while(1){
        printf("\n choose 1 to create \n");
        printf("\n choose 2 to insert rear \n");
        printf("\n choose 3 to delete rear \n");
        printf("\n choose 4 to insert at givin pos \n");
        printf("\n choose 5 to delete at given pos \n");
        printf("\n choose 6 to insert after node \n");
        printf("\n choose 7 to insert before node \n");
        printf("\n choose 8 to display from head \n");
        printf("\n choose 9 to display from tail \n");
        printf("\n choose 10 to end \n");

        printf("\n Enter your choice \n");
        scanf("%d",&choice);

        switch(choice){
            case 1:{
                create_list();
                display();
                break;
            }

            case 2:{
                insert_rear();
                display();
                break;
            }

            case 3:{
                delete_rear();
                display();
                break;
            }

            case 4:{
                insert_at_given_pos();
                display();
                break;
            }

            case 5:{
                delete_at_pos();
                display();
                break;
            }

            case 6:{
                insert_after_node();
                display();
                break;
            }

            case 7:{
                insert_before_node();
                display();
                break;
            }

            case 8:{
                display();
                break;
            }

            case 9:{
                display_tail();
                break;
            }

            case 10:{
                exit(0);
            }

            default :{
                printf("invalid choice \n");
            }
            


        }


    }
}
