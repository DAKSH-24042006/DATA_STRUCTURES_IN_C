#include<stdio.h>

// SUB QUESTION 1
int stringcount(char str[]){
    int i=0;
    int count=0;
    while (str[i] !="\0")
    {
       count =count+1;
       i++;
    }
    return count;
}

// SUB QUESTION 2
void strconcatination(char str1[],char str2[]){
    int i=0;
    int j=0;
    while(str1[i] != "\0"){
        i++;
    }

    while(str2[j] !="\0"){
        str1[i]=str2[j];
        i++;
        j++;
    }

    int k=0;
    while(str1[k] !="\0"){
        printf("%c",str1[k]);
        k++;
    }

}


// 


int main(){

}