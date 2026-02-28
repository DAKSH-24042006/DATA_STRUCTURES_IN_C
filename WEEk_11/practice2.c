#include <stdio.h>
#include<stdlib.h>

#define max 10

int adj_matrix[max][max];
int visited[max];
int n;

void create_adj_matrix(int directed){
    int src,dest;
    printf("\nEnter the number of vertices :");
    scanf("%d",&n);
    int edges;
    printf("Enter the number of edges :");
    scanf("%d",&edges);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adj_matrix[i][j]=0;
        }
    }

    printf("\nEnter the edges :");
    for(int i=1;i<=edges;i++){
        printf("\nsrc :");
        scanf("%d",&src);
        printf("\ndest :");
        scanf("%d",&dest);

        adj_matrix[src][dest]=1;

        if(directed==0){
            adj_matrix[dest][src]=1;
        }
    }
}

void display_adj_matrix(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           printf("%d\t", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

struct node{
    int data;
    struct node *next;
};

struct node *adj_list[max];

struct node* create_node(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void create_adj_list(int directed){
    int src,dest;
    printf("\nEnter the number of vertices :");
    scanf("%d",&n);
    int edges;
    printf("Enter the number of edges :");
    scanf("%d",&edges);

    for(int i=1;i<=n;i++){
        adj_list[i]=NULL;
    }

    for(int i=1;i<=edges;i++){
        printf("\nsrc :");
        scanf("%d",&src);
        printf("\ndest :");
        scanf("%d",&dest);

        struct node *newnode=create_node(dest);
        newnode->next=adj_list[src];
        adj_list[src]=newnode;

        if(directed==0){
            struct node *newnode=create_node(src);
            newnode->next=adj_list[dest];
            adj_list[dest]=newnode;
        }
    }
}

void display_adj_list(){
    for(int i=1;i<=n;i++){
        printf("%d-> ",i);
        while(adj_list[i]!=NULL){
            printf("%d ",adj_list[i]->data);
            adj_list[i]=adj_list[i]->next;
        }
        printf("\n");
    }
}

void bfs(int start){
    int queue[max];
    int rear=-1,front=-1;

    for(int i=1;i<=n;i++){
        visited[i]=0;
    }

    visited[start]=1;
    queue[++rear]=start;

    while(front <= rear){
        int v=queue[++front];
        printf("%d\t",v);

        for(int i=1;i<=n;i++){
            if( adj_matrix[v][i]==1 && visited[i]!=1){
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}

void dfs(int start){
    
    visited[start]=1;
    printf("%d\t",start);

    for(int i=1;i<=n;i++){
            if( adj_matrix[start][i]==1 && visited[i]!=1){
                dfs(i);
            }
        }


}


int main(){
    create_adj_matrix(1);
    display_adj_matrix();
    for(int i=1;i<=n;i++){
        visited[i]=0;
    }

    dfs(1);
    printf("\n");
    bfs(1);
}