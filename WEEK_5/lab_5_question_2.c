#include <stdio.h>
#include <stdlib.h>

struct node{
    int cof;
    int expo;
    struct node *next;
    struct node *prev;
};
struct node *head1=NULL;
struct node *head2=NULL;
struct node *head3=NULL;

void create_first_pol(){
    printf("\nCREATING FIRST POL");
    struct node *temp, *newnode;
    int choice =1;

    while(choice){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the coefficient :");
        scanf("%d",&newnode->cof);
        printf("\nEnter the exponenet :");
        scanf("%d",&newnode->expo);
        newnode->next=NULL;
        newnode->prev=NULL;

        if(head1 == NULL){
            head1=newnode;
            temp=newnode;
        }
        else{
            newnode->prev=temp;
            temp->next=newnode;
            temp=newnode;
        }

        printf("\nEnter '1' to continue and '0' to stop : ");
        scanf("%d",&choice);
    }
}

void create_second_pol(){
    printf("\nCREATING SECOND POL");
    struct node *temp, *newnode;
    int choice =1;

    while(choice){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the coefficient :");
        scanf("%d",&newnode->cof);
        printf("\nEnter the exponenet :");
        scanf("%d",&newnode->expo);
        newnode->next=NULL;
        newnode->prev=NULL;

        if(head2 == NULL){
            head2=newnode;
            temp=newnode;
        }
        else{
            newnode->prev=temp;
            temp->next=newnode;
            temp=newnode;
        }

        printf("\nEnter '1' to continue and '0' to stop : ");
        scanf("%d",&choice);
    }
}

void display_first(){
    printf("\nDISPLAY FIRST POL\n");
    struct node *temp;
    temp=head1;

    while(temp != NULL){
        printf("%d x %d \t",temp->cof,temp->expo);
        temp=temp->next;
    }
}

void display_second(){
    printf("\nDISPLAY SECOND POL\n");
    struct node *temp;
    temp=head2;

    while(temp != NULL){
        printf("%d x %d \t",temp->cof,temp->expo);
        temp=temp->next;
    }
}

void adding(){
    printf("\n ADDING THE TWO\n");
    struct node *temp1=head1;
    struct node *temp2=head2;

    while((temp1 !=NULL) && (temp2!=NULL)){
        if(temp1->expo > temp2->expo){
            insert_at_end(temp1->cof,temp1->expo);
            temp1=temp1->next;
        }
        else if(temp2->expo > temp1->expo){
            insert_at_end(temp2->cof,temp2->expo);
            temp2=temp2->next;
        }
        else{
            int c= temp1->cof + temp2->cof;
            insert_at_end(c,temp1->expo);
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }

    while(temp1 != NULL){
        insert_at_end(temp1->cof,temp1->expo);
        temp1=temp1->next;
    }

    while(temp2 != NULL){
        insert_at_end(temp2->cof,temp2->expo);
        temp2=temp2->next;
    }
}

struct node *tempnew=NULL;
void insert_at_end(int coeff,int expo){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->cof=coeff;
    newnode->expo=expo;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(head3==NULL){
        head3=newnode;
        tempnew=newnode;
    }
    else{
        tempnew->next=newnode;
        newnode->prev=tempnew;
        tempnew=newnode;
    }

}

void display_third(){
    printf("\nDISPLAY THIRD POL\n");
    struct node *temp;
    temp=head3;

    while(temp != NULL){
        printf("%d x %d \t",temp->cof,temp->expo);
        temp=temp->next;
    }
}

int main(){
    create_first_pol();
    display_first();

    create_second_pol();
    display_second();

    adding();
    display_third();


}

