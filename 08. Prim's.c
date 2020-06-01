// Program 8 : Prim’s Algorithm – to find spanning tree

#include<stdio.h>
#define INFINITY 100000
/*

OUTPUT

        Please enter the number of nodes:: 5

        Enter cost matrix::
        5       0       999     6       8
        7       999     0       4       4
        999     8       4       0       5
        0       5       7       999     2
        2       8       4       5       0
        

        Enter source node:: 1

        1 --> 2 = 0 Sum = 0


        2 --> 3 = 0 Sum = 0


        3 --> 4 = 0 Sum = 0


        4 --> 5 = 2 Sum = 2

*/
void prims(int n,int cost[10][10],int source){
    int visited[10]; //visited . keeps track to nodes visited and not
    int distance[10]; //distance. keeps latest shortest distance from source
    int i, j; //index variables
    int vertex[10]; //keeps track of nearest node to spanning tree
    int u, least, sum=0;

    //1. Initialisation
    for(i=1;i<=n;i++){
        visited[i] = 0; //visited array
        distance[i] = cost[source][i]; //distance array
        vertex[i] = source; //nearest node to spanning tree
    }
    visited[source] = 1; //mark source node as visited

    //2. n iteration
    for(i=1;i<n;i++){
        least = INFINITY;
        //2a) Find u and d(u) such that d(u) is least
        for(j=1; j<=n; j++)        {
            if(visited[j] == 0 && distance[j] < least){
                least = distance[j];
                u = j;
            }
        }
        //2b) mark node u as visited
        visited[u] = 1;
        sum += distance[u];
        printf("%d --> %d = %d currSum = %d\n\n",vertex[u],u,distance[u],sum);
        //2c) update d[] array. Explore paths through node u.
        for(j=1;j<=n;j++){
            if(visited[j] == 0 && cost[u][j] < distance[j]){
                distance[j] = cost[u][j];
                vertex[j] = u;
            }
        }
    }
    printf("Total cost: %d",sum);
}
int main(){
        
    int n; //no. of nodes
    int cost[10][10]; //Adjacency matrix of graph
    int source; //source node
    int i, j; //index variables
    printf("Enter n (no. of nodes): ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n ");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &cost[i][j]);
    printf("Enter Source: ");
    scanf("%d", &source);
    prims(n, cost, source);
    return 0;
}
