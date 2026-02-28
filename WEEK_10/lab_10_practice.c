#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createnode(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* insert(struct node *root,int data){
    if(root==NULL) return createnode(data);
    else if (data < root->data){
        root->left=insert(root->left,data);
    }
    else if (data > root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

void display_inorder(struct node *root){
    if(root==NULL){
        return;
    }
    display_inorder(root->left);
    printf("%d\t",root->data);
    display_inorder(root->right);
}

void display_preorder(struct node *root){
    if(root==NULL){
        return;
    }
    printf("%d\t",root->data);
    display_preorder(root->left);
    display_preorder(root->right);
}


void display_postorder(struct node *root){
    if(root==NULL){
        return;
    }
    display_postorder(root->left);
    display_postorder(root->right);
    printf("%d\t",root->data);
}

struct node* find_min(struct node *root){
    while(root->left!=NULL) root=root->left;
    return root;
}

struct node* find_max(struct node *root){
    while(root->right!=NULL) root=root->right;
    return root;
}





int main(){
    struct node *root=NULL;
    int n;
    printf("\nEnter the number of nodes to insert :");
    scanf("%d",&n);
    printf("\nEnter the elements :\n");

    for(int i=0;i<n;i++){
        int element;
        scanf("%d",&element);
        root=insert(root,element);
    }

    struct node *min=find_min(root);
    struct node *max=find_max(root);

    printf("\nThe inorder display is :\n");
    display_inorder(root);
    printf("\nThe preorder display is :\n");
    display_preorder(root);
    printf("\nThe postorder display is :\n");
    display_postorder(root);
    printf("\nThe min is %d :\n",&min->data);
    printf("\nThe max is %d :\n",&max->data);

    

}