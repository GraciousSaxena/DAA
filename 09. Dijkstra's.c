#include <stdio.h>
#define INFINITY 999

void dijk(int cost[10][10],int n,int source,int v[10],int d[10])
{
    int least, i, j, u;

    v[source] = 1;

    for(i=1; i<=n; i++)
    {

        least = INFINITY;

        for(j=1; j<=n; j++)
        {
            if(v[j] == 0 && d[j] < least)
            {
                least = d[j];
                u = j;
            }
        }

        v[u] = 1;

        for(j=1; j<=n; j++)
        {
            if(v[j] == 0 && (d[j] > (d[u] + cost[u][j])) )
                d[j] = d[u] + cost[u][j];
        }
    }
} 

int main()
{
    int n; //no. of nodes
    int cost[10][10]; //Adjacency matrix of graph
    int source; 
    int v[10]; 
    int d[10]; 
    int i, j; 

    printf("\nEnter n: ");
    scanf("%d", &n);

    printf("\nEnter Cost matrix: \n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &cost[i][j]);

    printf("\nEnter Source: ");
    scanf("%d", &source);

    for(i=1; i<=n; i++)
    {
        d[i] = cost[source][i];
        v[i] = 0;
    }

    dijk(cost, n, source, v, d);

    printf("\nShortest distance from source %d\n\n",source);

    for(i=1; i<=n; i++)
        printf("%d --> %d = %d \n\n", source, i, d[i]);

    return 0;
    /*

PS H:\Career\DAA> g++ .\10Dijkstra.c
PS H:\Career\DAA> .\a.exe
Enter n: 5
Enter Cost matrix: 
0 3 7 999 999
3 0 2 4 999
7 2 0 5 4
999 4 5 0 6
999 999 4 6 0
Enter Source: 1
Shortest distance from source 1

1 --> 1 = 0

1 --> 2 = 3

1 --> 3 = 5

1 --> 4 = 7

1 --> 5 = 9

    */
}

