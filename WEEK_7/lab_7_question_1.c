#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Stack functions
void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
}
char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}
int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Palindrome check
void palindromeCheck() {
    char str[MAX];
    top = -1;  // reset stack
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);
    for (int i = 0; i < len; i++) push(str[i]);

    int isPal = 1;
    for (int i = 0; i < len; i++) {
        if (str[i] != pop()) {
            isPal = 0;
            break;
        }
    }
    if (isPal) printf("Palindrome\n");
    else printf("Not Palindrome\n");
}

// Parentheses check
void parenthesesCheck() {
    char exp[MAX];
    top = -1;  // reset stack
    printf("Enter an expression: ");
    scanf("%s", exp);

    int valid = 1;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1 || !isMatching(pop(), exp[i])) {
                valid = 0;
                break;
            }
        }
    }
    if (top != -1) valid = 0;

    if (valid) printf("Parentheses are balanced\n");
    else printf("Parentheses are NOT balanced\n");
}

// Main menu
int main() {
    int choice;
    do {
        printf("\n--- ARRAY STACK MENU ---\n");
        printf("1. Palindrome Check\n");
        printf("2. Parentheses Matching\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: palindromeCheck(); break;
            case 2: parenthesesCheck(); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}
