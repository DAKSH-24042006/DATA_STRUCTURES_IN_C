#include <stdio.h>

int selection_sort(int *arr,int n){
    for(int i=0;i<n;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
                if((*(arr+))>(*(arr+j+1))){
                    min_index=j+1;

                }
        }
    }
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){

}