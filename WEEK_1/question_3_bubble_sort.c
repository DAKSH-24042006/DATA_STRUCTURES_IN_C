#include <stdio.h>

int main(){

    // bubble sort
    int n;
    printf("Enter the number of elements \n");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the elements : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    printf("The sorted array is : \n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

}