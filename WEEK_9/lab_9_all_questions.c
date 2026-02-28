#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ---------- Structure for Binary Tree Node ----------
struct Node {
    int data;
    struct Node *left, *right;
};

// ---------- Helper: Create a new node ----------
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// ---------- (2.i) Recursive Function to Create a Binary Tree ----------
struct Node* createTree() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1) return NULL;

    struct Node* root = createNode(data);
    printf("Enter left child of %d\n", data);
    root->left = createTree();
    printf("Enter right child of %d\n", data);
    root->right = createTree();

    return root;
}

// ---------- (1.i) Inorder Traversal (Iterative) ----------
void inorderIterative(struct Node* root) {
    struct Node* stack[MAX];
    int top = -1;
    struct Node* curr = root;

    while (curr || top != -1) {
        while (curr) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

// ---------- (1.iii) Preorder Traversal (Iterative) ----------
void preorderIterative(struct Node* root) {
    if (!root) return;
    struct Node* stack[MAX];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        struct Node* node = stack[top--];
        printf("%d ", node->data);
        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
}

// ---------- (1.ii) Postorder Traversal (Iterative) ----------
void postorderIterative(struct Node* root) {
    if (!root) return;
    struct Node *stack1[MAX], *stack2[MAX];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;
    while (top1 != -1) {
        struct Node* node = stack1[top1--];
        stack2[++top2] = node;
        if (node->left) stack1[++top1] = node->left;
        if (node->right) stack1[++top1] = node->right;
    }
    while (top2 != -1) printf("%d ", stack2[top2--]->data);
}

// ---------- (1.iv) Print Parent of a Given Element ----------
void printParent(struct Node* root, int key) {
    if (!root) return;
    if ((root->left && root->left->data == key) ||
        (root->right && root->right->data == key)) {
        printf("Parent of %d is %d\n", key, root->data);
        return;
    }
    printParent(root->left, key);
    printParent(root->right, key);
}

// ---------- (1.v) Find Height (Depth) ----------
int height(struct Node* root) {
    if (!root) return 0;
    int left = height(root->left);
    int right = height(root->right);
    return (left > right ? left : right) + 1;
}

// ---------- (1.vi) Print Ancestors ----------
int printAncestors(struct Node* root, int key) {
    if (!root) return 0;
    if (root->data == key) return 1;
    if (printAncestors(root->left, key) || printAncestors(root->right, key)) {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

// ---------- (1.vii) Count Leaf Nodes ----------
int countLeaves(struct Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

// ---------- (2.ii) Recursive Print (Inorder as example) ----------
void inorderRecursive(struct Node* root) {
    if (!root) return;
    inorderRecursive(root->left);
    printf("%d ", root->data);
    inorderRecursive(root->right);
}

// ---------- MAIN FUNCTION ----------
int main() {
    struct Node* root = createTree();

    printf("\nInorder Traversal (Iterative): ");
    inorderIterative(root);

    printf("\nPreorder Traversal (Iterative): ");
    preorderIterative(root);

    printf("\nPostorder Traversal (Iterative): ");
    postorderIterative(root);

    int key;
    printf("\n\nEnter element to find parent: ");
    scanf("%d", &key);
    printParent(root, key);

    printf("Height of tree = %d\n", height(root));

    printf("Enter element to print ancestors: ");
    scanf("%d", &key);
    printf("Ancestors of %d: ", key);
    if (!printAncestors(root, key))
        printf("Not found\n");
    else
        printf("\n");

    printf("Number of leaf nodes = %d\n", countLeaves(root));

    printf("Recursive Inorder Traversal: ");
    inorderRecursive(root);
    printf("\n");

    return 0;
}
