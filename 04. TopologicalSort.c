#include<stdio.h>
#include<stdlib.h>

int n, visited1[10], visited[10], connection[10][10],s1[10], top1, s2[10], top2, indegree[10];

void connect(int i, int j){
        if(i>10 || j>10){
                printf("The connection is not possible");
                return;
        }
        printf("\n\tConnecting %d with %d", i, j);
        connection[i-1][j-1] = 1;
        indegree[j-1] += 1;
}

void dfs(int src){
        int i,j;
        if(visited[src-1] == 0){
                s1[top1++] = src;
                visited[src-1] = 1;
                for(j=0; j<10; j++){
                        if(connection[src-1][j] == 1 && visited[j] == 0){
                                dfs(j+1);
                        }
                }
        }

        if(visited[src-1] == 1){
                for(i=0; i<10; i++){
                        if(connection[src-1][i] == 1 && visited[i] == 0){

                                dfs(i+1);
                        }
                }
                s2[top2++] = s1[--top1];
        }
}

void deletesrc(int src){
        int i,j;
        if(src>n)       return;
        if(visited1[src-1] == 0){
                visited1[src-1] = 1;
                printf("%d ", src);
                for(i=0; i<n; i++){
                        if(connection[src-1][i] == 1){
                                indegree[i] -= 1;
                        }
                }
                for(i=0; i<n; i++){
                        if(indegree[i] == 0 && visited1[i] == 0){
                                deletesrc(i+1);
                        }
                }
        }
}
void delsrc(){
        int i;
        printf("\n\tThe topologically sorted elements are:: \n\n\t");
        for(i=0; i<10; i++){
                if(indegree[i] == 0){
                        deletesrc(i+1);
                        return;
                }
        }
}
int main(){
        int i;
        connect(2,1);
        connect(2,4);
        connect(1,3);
        connect(1,4);
        connect(3,5);
        connect(4,3);
        connect(4,5);
        /*
        connect(1,2);
        connect(2,4);
        connect(1,3);
        connect(3,4);
        connect(4,5);
        */   
        n=5;
        dfs(2);
        printf("\n\n\tThe DFS Topological traversal is::\n\n\t");
        for(i=top2-1; i>-1; i--)
                printf("%d ", s2[i]);
        printf("\n\n\tThe visited list is:: \n\n\t");
        for(i=0; i<10; i++)
                printf("%d ", visited[i]);
        printf("\n");
        delsrc();
        printf("\n\n");
        return 0;                                             
} 

