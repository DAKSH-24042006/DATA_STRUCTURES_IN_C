#include <stdio.h>
#include <stdlib.h>

#define max 10

int adj_matrix[max][max];
int visited[max];
int n;

void create_adj_matrix(int directed){
    int edges,src,dest;
    printf("Enter the number of vertex : ");
    scanf("%d",&n);
    printf("Enter the number of edges : ");
    scanf("%d",&edges);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adj_matrix[i][j]=0;
        }
    }

    printf("Enter the edges with source first then the destination :\n");
    for(int i=0;i<edges;i++){

        printf("Enter the source : ");
        scanf("%d",&src);
        printf("Enter the destination : ");
        scanf("%d",&dest);
        adj_matrix[src][dest]=1;
        if(directed==0){
            adj_matrix[dest][src]=1;
        }
    }

    printf("\nThe adj matrix is : \n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d\t",adj_matrix[i][j]);
        }
        printf("\n");
    }

}

struct node{
    int data;
    struct node* next;
};

struct node* adj_list[max];

struct node* create_node(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void create_adj_list(int directed){
    int edges,src,dest;
    printf("\nEnter the number of vertices : ");
    scanf("%d",&n);
    printf("\nEnter the number of edges :");
    scanf("%d",&edges);

    for(int i=1;i<=n;i++){
        adj_list[i]=NULL;
    }

    printf("\nEnter the edges source and destinations :");
    for(int i=1;i<=edges;i++){
        printf("ENter the source : ");
        scanf("%d",&src);
        printf("\nENter the destination : ");
        scanf("%d",&dest);

        struct node* newnode=create_node(dest);
        newnode->next=adj_list[src];
        adj_list[src]=newnode;


        if(directed==1){
            struct node* newnode=create_node(src);
            newnode->next=adj_list[dest];
            adj_list[dest]=newnode;
        }

    }

    printf("printing the adj list \n");
    for(int i=1;i<=n;i++){
        printf("\n %d -> ",i);
        while(adj_list[i] != NULL){
            printf("%d \t",adj_list[i]->data);
            adj_list[i]=adj_list[i]->next;
        }
    }


}

void bfs(int start){
    
    int queues[max];
    int front=-1,rear=-1;

    for(int i=1;i<=n;i++){
        visited[i]=0;
    }
    visited[start]=1;

    queues[++rear]=start;

    printf("\nBFS :\n");
    while(front<rear){
        int v=queues[++front];
        printf("%d\t",v);

        for(int i=1;i<=n;i++){
            if(adj_matrix[v][i]==1 && visited[i]==0){
                queues[++rear]=i;
                visited[i]=1;
            }
        }

    }
    printf("\n");
}

void dfs(int v){
    visited[v]=1;
    printf("%d\t",v);
    for(int i=1;i<=n;i++){
        if( adj_matrix[v][i] && !visited[i] ){
            dfs(i);
        }
    }
}

int main(){
    create_adj_list(0);
}