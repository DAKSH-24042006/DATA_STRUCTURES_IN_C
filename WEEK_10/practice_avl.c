#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    int hight;
};

int get_hight(struct node *root){
    if(root==NULL){
        return 0;
    }
    return root->hight;
}

int max(int a,int b){
    return (a>b ? a:b);
}

int get_balance_factor(struct node *root){
    if(root==NULL) return 0;
    return ( get_hight(root->left)-get_hight(root->right) );
}


struct node* right_rotate(struct node *y){
    struct node *x = y->left;
    struct node *t2 = x->right;

    x->right=y;
    y->left=t2;

    x->hight =1+ max( get_hight(x->left),get_hight(x->right) );
    y->hight =1+ max( get_hight(y->left),get_hight(y->right) );

    return x;


}

struct node* lef_rotate(struct node *x){
    struct node *y = x->right;
    struct node *t2 = y->left;

    y->left=x;
    x->right=t2;

    x->hight =1+ max( get_hight(x->left),get_hight(x->right) );
    y->hight =1+ max( get_hight(y->left),get_hight(y->right) );

    return y;


}

struct node* create_node(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->hight=1;
    return newnode;
}

struct node* insert(struct node *root,int data){
    if(root==NULL){
        return create_node(data);
    }

    else if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }

    root->hight=1+max( get_hight(root->left),get_hight(root->right) );
    int balance=get_balance_factor(root);

    if(balance>1 && data<root->left->data){
        return right_rotate(root);
    }
    if(balance<-1 && data>root->right->data){
        return lef_rotate(root);
    }
    if(balance>1 && data>root->left->data){
        root->left=lef_rotate(root);
        return right_rotate(root);
    }
    if(balance<-1 && data<root->right->data){
        root->right=right_rotate(root);
        return lef_rotate(root);
    }

    return root;

}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder Traversal of AVL Tree: ");
    inorder(root);

    return 0;
}
