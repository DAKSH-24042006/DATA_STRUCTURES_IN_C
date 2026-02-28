#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* create_tree(){
    int element;
    printf("\nEnter the element (enter -1 to null):");
    scanf("%d",&element);
    if(element==-1){
        return NULL;
    }

    struct node *root=create_node(element);
    printf("\nEnter the left child of %d :",element);
    root->left=create_tree();
    printf("\nEnter the right child of %d :",element);
    root->right=create_tree();

    return root;
    


}

void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}

void find_parent(struct node *root,int key){
    if(root->data==key){
        return;
    }
    if( (root->left->data==key) || (root->right->data==key) ){
        printf("\nThe parent of %d is %d",key,root->data);
        return;
        
    }

    find_parent(root->left,key);
    find_parent(root->right,key);


}

int find_hight(struct node *root){
    if(root==NULL){
        return 0;
    }
    int left=find_hight(root->left);
    int right=find_hight(root->right);

    return (left>right ? left : right)+1 ;

}

int count_leaf(struct node *root){
    if(root==NULL){
        return 0;
    }
    if( (root->left==NULL) && (root->right==NULL) ){
        return 1;
    }

    return count_leaf(root->left)+count_leaf(root->right);
}


int main(){
    struct node *root=NULL;
    root=create_tree();
    printf("\n");
    inorder(root);
    find_parent(root,2);
    printf("\n");
    printf("The hight of the tree is %d",find_hight(root));
    printf("\n");
    printf("The no. of leaves is %d",count_leaf(root));


}