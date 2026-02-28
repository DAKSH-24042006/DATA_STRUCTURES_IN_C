#include <stdio.h>

int main(){

    ///INPUT ELEMENTS FOR SEARCH
/*    int arr[6];
    printf("Enter 6 numbers ");
    for(int i=0;i<6;i++){
        scanf("%ld", &arr[i]);
    }*/


    ///LINEAR SEARCH
 /*   int key=3;

    for(int i=0;i<6;i++){
        if(arr[i]==key){
            printf("The number is %d",arr[i]);

        }
    }*/

    ///BINARY SEARCH
 /*   int search=4;
    int first=0;
    int last=(6-1);
    int middle=(first+last)/2;


    while(first<=last){
            if(arr[middle]<search){
                first=middle+1;
            }
            else if(arr[middle]==search){
                printf("found the number , it is %d at %d",arr[middle],(middle+1));
                break;
            }
            else{
                last=middle-1;
            }

            middle=(first+last)/2;
    }*/


    ///INPUT OF ELEMENTS FOR SORT
/*    int brr[7];
    printf("Enter 7 numbers ");
    for(int i=0;i<7;i++){
        scanf("%ld", &brr[i]);
    }

    int comp=0;
    int swaps=0;*/


    ///BUBBLE SORT ASCENDING ORDER
 /*   int size=7;
    for(int i=0;i<7-1;i++){

        for(int j=0;j<7-i-1;j++){
            comp=comp+1;
            if(brr[j]>brr[j+1]){
                swaps=swaps+1;
                int temp=brr[j];
                brr[j]=brr[j+1];
                brr[j+1]=temp;
            }
        }
    }

    for(int i=0;i<7;i++){
        printf("%d\n",brr[i]);
    }*/

    ///NUMBER OF COMPARISIONS
 //   printf("The number of comparison made is %d\n",comp);

    ///NUMBER OF SWAPS
 //   printf("The number of swaps made is %d\n",swaps);


    ///SELECTION SORT
 /*   int min_index,temp;
    for(int i=0;i<7-1;i++){
        min_index=i;
        for(int j=i+1;j<7;j++){
            if(brr[j]<brr[min_index]){
                min_index=j;
            }
        }

        temp=brr[min_index];
        brr[min_index]=brr[i];
        brr[i]=temp;
    }*/

    ///ASCENDING ORDER
/*    printf("The sorted array is \n");
    for(int i=0;i<7;i++){
        printf("%d\n",brr[i]);
    }*/

    ///IN DESCENDING ORDER
/*    for(int i=0;i<7;i++){
        printf("%d\n",brr[7-i-1]);
    }*/

    ///INSERTION SORT


    ///ADDITIONAL 2ND
/*    int arr[3][3];
    int brr[3][3];
    int crr[3][3];
    printf("Enter the first 3*3 matrix elements \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%ld",&arr[i][j]);
        }
    }

    printf("Enter the Second 3*3 matrix elements \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%ld",&brr[i][j]);
        }
    }

    printf("find max \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
           if(arr[i][j]>brr[i][j]){
            crr[i][j]=arr[i][j];
           }

           else if(arr[i][j]<brr[i][j]){
            crr[i][j]=brr[i][j];
           }

           else{
            crr[i][j]=arr[i][j];
           }
        }
    }

    printf("max of array crr is /n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",crr[i][j]);
        }
        printf("\n");
    }*/





    ///ADDITIONAL 3RD
    ///sub 1
/*    int arr[3][3];
    int brr[3][3];
    int crr[3][3];
    printf("Enter the first 3*3 matrix elements \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%ld",&arr[i][j]);
        }
    }

    printf("Enter the Second 3*3 matrix elements \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%ld",&brr[i][j]);
        }
    }

    printf("multiplication of two matrices \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            crr[i][j]=(arr[i][j]*brr[i][j]);
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",crr[i][j]);
        }
        printf("\n");
    }*/


    ///sub 2
/*    int arr[3][3];
    int brr[3][3];
    int crr[3][3];
    printf("Enter the first 3*3 matrix elements \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%ld",&arr[i][j]);
        }
    }

    printf("Enter the Second 3*3 matrix elements \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%ld",&brr[i][j]);
        }
    }

    printf("addition of two matrices \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            crr[i][j]=(arr[i][j]+brr[i][j]);
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",crr[i][j]);
        }
        printf("\n");
    }*/





    return 0;
}
