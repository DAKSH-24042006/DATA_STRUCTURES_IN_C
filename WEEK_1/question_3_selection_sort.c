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

    int min_pos;
    for(int i=0;i<n-1;i++){
        min_pos=i;
        for(int j=i+1;j<n;j++){
            if(arr[min_pos]>arr[j]){
                min_pos=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min_pos];
        arr[min_pos]=temp;
    }

    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
}



}


