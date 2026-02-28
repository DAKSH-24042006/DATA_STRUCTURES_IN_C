#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Linked list stack (char)
struct Node {
    char data;
    struct Node* next;
};
struct Node* top = NULL;

void push(char c) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}
char pop() {
    if (top == NULL) return '\0';
    struct Node* temp = top;
    char c = temp->data;
    top = top->next;
    free(temp);
    return c;
}
char peek() {
    if (top == NULL) return '\0';
    return top->data;
}
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Linked list stack (int) for evaluation
struct NodeInt {
    int data;
    struct NodeInt* next;
};
struct NodeInt* topInt = NULL;

void pushInt(int val) {
    struct NodeInt* newNode = (struct NodeInt*)malloc(sizeof(struct NodeInt));
    newNode->data = val;
    newNode->next = topInt;
    topInt = newNode;
}
int popInt() {
    if (topInt == NULL) return 0;
    struct NodeInt* temp = topInt;
    int val = temp->data;
    topInt = topInt->next;
    free(temp);
    return val;
}

// Infix to Postfix
void infixToPostfix() {
    char infix[100], postfix[100];
    int k = 0;
    top = NULL; // reset stack

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != NULL && peek() != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        } else {
            while (top != NULL && precedence(peek()) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }
    while (top != NULL)
        postfix[k++] = pop();

    postfix[k] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

// Postfix Evaluation
void postfixEval() {
    char postfix[100];
    topInt = NULL; // reset int stack

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            pushInt(c - '0');
        } else {
            int b = popInt();
            int a = popInt();
            int res;
            switch (c) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                default: res = 0;
            }
            pushInt(res);
        }
    }
    printf("Result = %d\n", popInt());
}

// Main menu
int main() {
    int choice;
    do {
        printf("\n--- LINKED LIST STACK MENU ---\n");
        printf("1. Infix to Postfix\n");
        printf("2. Postfix Evaluation\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: infixToPostfix(); break;
            case 2: postfixEval(); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}

