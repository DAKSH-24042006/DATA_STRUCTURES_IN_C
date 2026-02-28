#include <stdio.h>
#include <stdlib.h>

#define max 100

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *createtree(){
    int data;
    printf("Enter the data (-1 for no node) : ");
    scanf("%d",&data);
    if(data==-1){
        return NULL;
    }

    struct node* root=createnode(data);
    printf("Enter the left child of %d :",data);
    root->left=createtree();
    printf("Enter the right child of %d :",data);
    root->right=createtree();

    return root;
}

void inorder_recursive(struct node* root){
    if(root == NULL){
       return;
    }
    inorder_recursive(root->left);
    printf("%d\t",root->data);
    inorder_recursive(root->right);
}

void preorder_recursive(struct node* root){
    if(root == NULL){
        return;
    }
    printf("%d\t",root->data);
    preorder_recursive(root->left);
    preorder_recursive(root->right);
}

void postorder_recursive(struct node* root){
    if(root == NULL){
        return ;
    }
    postorder_recursive(root->left);
    postorder_recursive(root->right);
    printf("%d\t",root->data);
}

void find_parent(struct node* root,int key){
    if(root==NULL){
        return ;
    }

    if(root->data==key){
        return ;
    }

    if( (root->left!=NULL &&root->left->data==key) || (root->right!=NULL &&root->right->data==key) ){
        printf("\nThe parent of the node is : %d",root->data);
        return ;
    }
    find_parent(root->left,key);
    find_parent(root->right,key);
}

int find_hight(struct node* root){
    if(root==NULL){
        return 0;
    }

    int left=find_hight(root->left);
    int right=find_hight(root->right);

    return (left>right?left:right)+1;


    
}




int main(){
    struct node* root;
    root=createtree();
    inorder_recursive(root);
    printf("\n");
    // preorder_recursive(root);
    // printf("\n");
    // postorder_recursive(root);
    // printf("\n");
    
    
    // find_parent(root,2);
    // printf("\nThe hight of the tree is %d",find_hight(root));
    
}