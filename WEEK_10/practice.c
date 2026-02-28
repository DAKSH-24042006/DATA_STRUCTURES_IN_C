#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* insert(int data,struct node* root){
    if(root==NULL){
        return create_node(data);
    }
    if(data<root->data){
        root->left= insert(data,root->left);
    }
    if(data>root->data){
       root->right= insert(data,root->right);
    }
    return root;
}

int search(int key , struct node* root){
    if(root==NULL){
        return 0;
    }
    if(root->data==key){
        return 1;
    }
    else{
        return search(key,root->left) || search(key,root->right);
    }
}

void inorder(struct node* root) {
   if(root==NULL){
    return;
   }
   inorder(root->left);
   printf("%d\t",root->data);
   inorder(root->right);
}

void find_min(struct node* root){
    if(root==NULL){
        return;
    }
    struct node* temp=root;
    while(temp->left != NULL){
        temp=temp->left;
    }
    printf("\nThe min is %d ",temp->data);
}

void find_max(struct node* root){
    if(root==NULL){
        return;
    }
    struct node* temp=root;
    while(temp->right != NULL){
        temp=temp->right;
    }
    printf("\nThe max is %d ",temp->data);
}

int main(){
    struct node* root=NULL;
    root=insert(5,root);
    root=insert(2,root);
    root=insert(3,root);
    inorder(root);
    printf("\n%d",search(2,root));
    find_min(root);
    find_max(root);
}
