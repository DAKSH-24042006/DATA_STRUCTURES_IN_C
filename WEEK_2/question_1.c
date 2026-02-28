#include <stdio.h>

int find_min(int *arr,int n){
    int min;
    for(int i=0;i<n;i++){
        if(*(arr+i)<min){
            min=*(arr+i);
        }
    }

    return min;
}

int main(){

    printf("Enter the size of the array : \n");
    int n;
    scanf("%d",&n);


    printf("Enter the elements of the array : \n");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("the smallest element of the array is : %d",find_min(arr,n));
    
}