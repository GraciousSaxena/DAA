#include <bits/stdc++.h>
using namespace std; 

const int N = 4; 
  
int final_path[N+1]; 
  
bool visited[N]; 
  
int final_res = INT_MAX; 
  
void copyToFinal(int curr_path[]) { 
    for (int i=0; i<N; i++) 
        final_path[i] = curr_path[i]; 

    final_path[N] = curr_path[0]; 
} 
  
int firstMin(int adj[N][N], int i) { 
    int min = INT_MAX; 
    for (int k=0; k<N; k++) 
        if (adj[i][k]<min && i != k) 
            min = adj[i][k]; 
    
    return min; 
} 
  
int secondMin(int adj[N][N], int i) { 
    int first = INT_MAX, second = INT_MAX; 
    for (int j=0; j<N; j++) 
    { 
        if (i == j) 
            continue; 
  
        if (adj[i][j] <= first) 
        { 
            second = first; 
            first = adj[i][j]; 
        } 
        else if (adj[i][j] <= second && 
                 adj[i][j] != first) 
            second = adj[i][j]; 
    } 
    return second; 
} 
  
void TSPRec(int adj[N][N], int curr_bound, int curr_weight, int level, int curr_path[]) { 
    if (level==N) { 
        if (adj[curr_path[level-1]][curr_path[0]] != 0) { 
            int curr_res = curr_weight + 
                    adj[curr_path[level-1]][curr_path[0]]; 
  
            if (curr_res < final_res) { 
                copyToFinal(curr_path); 
                final_res = curr_res; 
            } 
        } 
        return; 
    } 
  
    for (int i=0; i<N; i++) { 
        if (adj[curr_path[level-1]][i] != 0 && visited[i] == false) { 
            int temp = curr_bound; 
            curr_weight += adj[curr_path[level-1]][i]; 
  
            if (level==1) 
              curr_bound -= ((firstMin(adj, curr_path[level-1]) + firstMin(adj, i))/2); 
            else
              curr_bound -= ((secondMin(adj, curr_path[level-1]) + firstMin(adj, i))/2); 
  
            if (curr_bound + curr_weight < final_res) { 
                curr_path[level] = i; 
                visited[i] = true; 
  
                TSPRec(adj, curr_bound, curr_weight, level+1, curr_path); 
            } 
  
            curr_weight -= adj[curr_path[level-1]][i]; 
            curr_bound = temp; 
  
            memset(visited, false, sizeof(visited)); 
            for (int j=0; j<=level-1; j++) 
                visited[curr_path[j]] = true; 
        } 
    } 
} 
  
void TSP(int adj[N][N]) { 
    int curr_path[N+1]; 
    int curr_bound = 0; 
    memset(curr_path, -1, sizeof(curr_path)); 
    memset(visited, 0, sizeof(curr_path)); 
    for (int i=0; i<N; i++) 
        curr_bound += (firstMin(adj, i) + secondMin(adj, i)); 
  
    curr_bound = (curr_bound & 1)? curr_bound/2 + 1 : curr_bound/2; 
  
    visited[0] = true; 
    curr_path[0] = 0; 
  
    TSPRec(adj, curr_bound, 0, 1, curr_path); 
} 



int main() { 
    cout<<"\n";
    
    int adj[N][N]; 
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            adj[i][j] = 0;
            
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            cout<<"Enter the distance between "<<i<<" and "<<j<<" :: ";
            int dist;   cin>>dist;
            adj[i][j] = adj[j][i] = dist;
        }
    }
  
    TSP(adj); 
  
    printf("Minimum cost : %d\n", final_res); 
    printf("Path Taken : "); 
    for (int i=0; i<=N; i++) 
        printf("%d ", final_path[i]); 
  
    return 0; 

/*
    

        OUTPUT 1
    PS H:\Career> g++ .\Program12_TSP_usingBranchandBound.cpp
    PS H:\Career> .\a.exe

    Enter the distance between 0 and 1 :: 10
    Enter the distance between 0 and 2 :: 15
    Enter the distance between 0 and 3 :: 20
    Enter the distance between 1 and 2 :: 35
    Enter the distance between 1 and 3 :: 25
    Enter the distance between 2 and 3 :: 30
    Minimum cost : 80
    Path Taken : 0 1 3 2 0 

        OUTPUT 2

    PS H:\Career> .\a.exe

    Enter the distance between 0 and 1 :: 10
    Enter the distance between 0 and 2 :: 20
    Enter the distance between 0 and 3 :: 30
    Enter the distance between 1 and 2 :: 40
    Enter the distance between 1 and 3 :: 50
    Enter the distance between 2 and 3 :: 60
    Minimum cost : 140
    Path Taken : 0 1 2 3 0 

*/
}
