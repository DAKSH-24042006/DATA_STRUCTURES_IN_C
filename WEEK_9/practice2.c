#include <stdio.h>
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

struct node* create_tree(){
    int data;
    printf("\nEnter the data (-1 to stop) :");
    scanf("%d",&data);
    if(data==-1){
        return NULL;
    }

    struct node* newnode=create_node(data);
    printf("\nEnter the left child of %d: ",data);
    newnode->left=create_tree();
    printf("\nEnter the right child %d: ",data);
    newnode->right=create_tree();
    

}

void inorder_recursive(struct node* root){
    if(root==NULL){
        return;
    }
    inorder_recursive(root->left);
    printf("%d\t",root->data);
    inorder_recursive(root->right);
}

void preorder_recursive(struct node* root){
    if(root==NULL){
        return;
    }
    printf("%d\t",root->data);
    preorder_recursive(root->left);
    preorder_recursive(root->right);
    
}

void postorder_recursive(struct node* root){
    if(root==NULL){
        return;
    }
    postorder_recursive(root->left);
    postorder_recursive(root->right);
    printf("%d\t",root->data);
    
}

void find_parent(struct node* root,int key){
    if(root->data==key){
        return ;
    }
    if( (root->left->data==key) || (root->right->data==key) ){
        printf("The parent is %d\n",root->data);
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

    return (left>right ? left : right)+1 ;
    

}

int print_prev(struct node* root,int key){
    if(root==NULL){
        return 0;
    }
    if(root->data==key){
        return 1;
    }
    if( print_prev(root->left,key) || print_prev(root->right,key) ){
        printf("%d\t",root->data);
        return 1;
    }
    return 0;
}

int leaf_nodes(struct node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    return leaf_nodes(root->left)+leaf_nodes(root->right);
}




int main(){
    struct node* root;

    // creating tree
    root=create_tree();
    printf("\nindorder recusive :\n");
    inorder_recursive(root);
    // printf("\npreorder recusive :\n");
    // preorder_recursive(root);
    // printf("\npostorder recusive :\n");
    // postorder_recursive(root);
    // printf("\nFinding the parent of 2 :\n");
    // find_parent(root,2);
    // printf("\nFinding the ancestors of 4 :\n");
    // print_prev(root,4);
    // printf("\nFinding the no of leaf nodes:\n");
    // printf("The no of leaf nodes is %d\n",leaf_nodes(root));
    
}