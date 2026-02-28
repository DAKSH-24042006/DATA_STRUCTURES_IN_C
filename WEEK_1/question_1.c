// 21 7 25 first lab

#include <stdio.h>

int main(){

    int n;
    printf("Enter the number of elements \n");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the elements : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter the key : \n");
    int key;
    scanf("%d",&key);

    for(int i=0;i<n;i++){
        if(arr[i]==key){
            printf("The element was found in %d ",i+1);
        }
    }
}