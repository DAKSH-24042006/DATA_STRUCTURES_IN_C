#include <stdio.h>
#include <stdlib.h>

struct cart{
    int id;
    char pname[50];
    char category[50];
    float price;
};

void read(struct cart *c1){
    printf("\nEnter the id :");
    scanf("%d",&c1->id);
    printf("enter the name :");
    scanf(" %[^\n]", c1->pname);
    printf("Enter the category :");
    scanf(" %[^\n]", c1->category);
    printf("\nEnter the price :");
    scanf("%f",&c1->price);
}

void display(struct cart c1){
    printf("\n----cart info---\n");
    printf("The id is : %d\n",c1.id);
    printf("The name is : %s\n",c1.pname);
    printf("The category is : %s\n",c1.category);
    printf("The price is %f",c1.price);
}

void swap(struct cart *a,struct cart *b){
    struct cart temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_recursively_sort(struct cart c[],int n){
    
    if(n==1){
        return ;
    }
    else{
        for(int i=0;i<n-1;i++){
            if(c[i].price > c[i+1].price){
                swap(&c[i],&c[i+1]);
            }
        }
    }

    bubble_recursively_sort(c,n-1);
}

void selection_recursively_sort(struct cart c[],int n,int index){
    if(index == n){
        return ;
    }
    
    int min_index=index;
    for(int i=index+1;i<n;i++){
        if(c[i].price < c[min_index].price){
            min_index=i;
        }
    }
    swap(&c[index],&c[min_index]);

    selection_recursively_sort(c,n,index+1);
    
}

int main(){
    printf("Enter the number of carts");
    int n;
    scanf("%d",&n);
    struct cart *c1=(struct cart *)malloc(n * sizeof(struct cart));

    for(int i=0;i<n;i++){
        read(&c1[i]);
    }

    for(int i=0;i<n;i++){
        display(c1[i]);
    }


    // printf("\n----AFTER BUBBLE SORT----\n");
    // bubble_recursively_sort(c1,n);
    // for(int i=0;i<n;i++){
    //     display(c1[i]);
    // }

    printf("\n----AFTER SELECTION SORT----\n");
    selection_recursively_sort(c1,n,0);
    for(int i=0;i<n;i++){
        display(c1[i]);
    }
}