#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

char expression[max];
char reversed[max];

void push(char c){
    if(top2 == max-1){
        printf("The stack is full\n");
    }
    else{
        reversed[++top2]=c;
    }
}

char pop1(){
    if(top1 == -1){
        printf("The stack is empty\n");
        return;
    }

    else{
        return expression[top1--];
    }
}

char pop2(){
    if(top1 == -1){
        printf("The stack is empty\n");
        return;
    }

    else{
        return reversed[top2--];
    }
}

int top1=-1;
int top2=-1;

void check_palindrome(){
    int n=strlen(expression);
    for(int i=0 ; expression[i]!='\0' ; i++){
        push(expression[n-1]);
        n=n-1;
    }

    for(int i=0 ; expression[i]!='\0' ; i++){
        if(pop1() != pop2()){
            printf("it is not a palindrome\n");
            break;
        }
    }
    
    printf("it is a palindrome\n");
    
}

int main(){
    printf("Enter the expression :");
    gets(expression);
    check_palindrome();
}