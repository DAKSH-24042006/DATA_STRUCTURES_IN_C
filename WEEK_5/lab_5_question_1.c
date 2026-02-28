#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;

void create_list(){
    struct node *newnode, *temp;
    int choice =1;

    while(choice){

        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data :");
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL){
            head=newnode;
            temp=newnode;
            newnode->next=temp;
        }

        else{
            temp->next=newnode;
            newnode->next=head;
            temp=newnode;
        }

        printf("\nEnter '1' to continue and '0' to stop :");
        scanf("%d",&choice);
    }
}

void display_list(){

    struct node *temp;
    temp=head;
    printf("\n---The list is---\n");

    while(temp->next != head){
        printf("%d \t",temp->data);
        temp=temp->next;
    }
    printf("%d\t",temp->data);
}

void insert_element_atend(){
    printf("\nEnter the value  of the element you want to insert :");
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    struct node *temp;
    temp=head;

    while(temp->next != head){
        temp=temp->next;
    }


    newnode->next=temp->next;
    temp->next=newnode;
    temp=newnode;
}

void insert_element_at_pos(){
    printf("\nEnter the position in which you want to insert the element :");
    int pos;
    scanf("%d",&pos);

     printf("\nEnter the value  of the element you want to insert :");
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    struct node *temp;
    temp=head;


    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }

    
    newnode->next=temp->next;
    temp->next=newnode;
    
}

void delete_element(){
    printf("\nEnter the element you want to delete : ");
    int n ;
    scanf("%d",&n);
    struct node *temp;
    temp=head;
    struct node *current;
    current=head;

    while(temp->next->data != n){
        temp=temp->next;
    }

    while(current->data != n){
            current=current->next;
    }

    temp->next=current->next;
    free(current);
}

int main(){
    //CREATE LIST
    create_list();
    display_list();

    //INSERT AT END
    // insert_element_atend();
    // display_list();
    // insert_element_atend();
    // display_list();

    //INSERT AT POS
    // insert_element_at_pos();
    // display_list();
    // insert_element_at_pos();
    // display_list();

    //DETETE
    delete_element();
    display_list();





    return 0;
}

