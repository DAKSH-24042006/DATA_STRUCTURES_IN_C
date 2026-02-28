#include<stdlib.h>
#include<stdio.h>

int main(){
    printf("Enter the size of 1st 2D matric \n");
    int r,c;
    scanf("%d %d",&r,&c);

    int **arr=(int **)malloc(r * sizeof(int *));
    for(int i=0;i<r;i++){
         *(arr + i )=(int *)malloc(c * sizeof(int));
    }

    printf("Enter the elements of the 2D array \n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",(*(arr+i)+j));
        }
    }
    
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d\t",*(*(arr+i)+j));
        }
        printf("\n");
    }

    printf("Enter the size of 2nd 2D matric \n");
    int r1,c1;
    scanf("%d %d",&r1,&c1);

    int **arr1=(int **)malloc(r * sizeof(int *));
    for(int i=0;i<r;i++){
         *(arr1 + i )=(int *)malloc(c * sizeof(int));
    }

    printf("Enter the elements of the 2D array \n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            scanf("%d",(*(arr1+i)+j));
        }
    }
    
    
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            printf("%d\t",*(*(arr1+i)+j));
        }
        printf("\n");
    }

    printf("The matrix multiplication is \n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            printf("%d\t",(*(*(arr1+i)+j))*(*(*(arr+i)+j)));
        }
        printf("\n");
    }
}