#include<stdio.h>
#include<stdlib.h>

int visited[10], queue[10], connection[10][10], front, rear;

void connect(int a, int b){
        if(a > 10 || b > 10){
                printf("\nInvalid Values!\n");
                return;
        }
        connection[a-1][b-1] = connection[b-1][a-1] = 1;

//      connection[a-1][b-1] = 1;
}

void dfs(int node){
        int i;
        if(visited[node-1] == 0){
                visited[node-1] = 1;
                printf("%d ", node);
                for(i=0;i<10; i++){
                        if(connection[node-1][i] == 1 && visited[i] == 0){
                                dfs(i+1);
                        }
                }
        }
}

void bfs(int node){
        int i;
        if(node < 1)
                return;
        if(visited[node-1] == 0){
                visited[node-1] = 1;
                printf("%d ", node);
                queue[rear++] = node;
                for(i=0; i<10; i++){
                        if(connection[node-1][i] == 1 && visited[i] == 0){
                                queue[rear++] = i+1;
                        }
                }
        }
        if(front <= rear)
                bfs(queue[front++]);
}

int main(){
        int i,flag=0, src, a, b, count=10;
        connect(1,2);
        connect(1,4);
        connect(2,3);
        connect(2,5);
        connect(2,7);
        connect(2,8);
        connect(3,4);
        connect(10,10);
        connect(3,9);
        connect(5,6);
        connect(5,7);
        connect(5,8);
        connect(7,8);

/*
        char ch = 'y';
        while(ch == 'y'){
                printf("\n\tEnter the vertices to be connected:: ");
                scanf("%d%d", &a, &b);
                printf("\tConnecting %d with %d\n", a, b);
                connect(a, b);
                count++;
                printf("\t\nContinue? ");
                scanf("  %c", &ch);
        }
*/      printf("\n\tEnter the source:: ");
        printf("\n\tEnter the source:: ");
        scanf("%d", &src);
        printf("\n\tDFS::\n\t\t");
        dfs(src);
        for(i=0; i<10; i++)
                visited[i] = 0;
        printf("\n\tBFS::\n\t\t");
        bfs(src);
        printf("\n\nThe vertices not visited are:: ");
        for(i=0; i<count; i++){
                if(visited[i] == 0){
                        flag = 1;
                        printf("%d",i+1);
                }
        }
        printf("\n");
        if(flag == 0)
                printf("all vertices are visited\n");
        return 0;
}

