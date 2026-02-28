#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

char stack[max];
int top=-1;

void push(char c){
    if(top < max-1){
        stack[++top]=c;
    }
}

char pop(){
    char v;
    if(top != -1){
        v=stack[top--];
    }
    return v;
}

void palindrome_check(char check[]){
    int length=strlen(check);

    for(int i=0;i<length;i++){
        push(check[i]);
    }

    int pal=1;
    for(int i=0;i<length;i++){
        if( check[i] != pop() ){
            pal=0;
            break;
        }
    }

    if(pal==1){
        printf("\nIt is a palindrome");
    }
    if(pal==0){
        printf("\nIt is not a palindrome");
    }


}

int is_matching(char a,char b){
    return ( (a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}') );
}

void check_balance(char expression[]){
    int valid=1;
    int length=strlen(expression);

    for(int i=0;i<length;i++){
        if( expression[i]=='(' || expression[i]=='{' || expression[i]=='[' ){
            push(expression[i]);
        }
        else if( expression[i]==')' || expression[i]=='}' || expression[i]==']' ){
            if( top==-1 || ( is_matching(pop(),expression[i])==0 ) ){
                valid=0;
                break;
            }
        }
    }
    if(top != -1){
        valid=0;
    }

    if(valid==1){
        printf("\nIt is a balanced expression");
    }
    if(valid==0){
        printf("\nIt is not balanced expression");
    }
}

int main(){

    char check[max];
    printf("\nEnter the word to ckeck :");
    scanf(" %[^\n]" ,check);
    check_balance(check);
}