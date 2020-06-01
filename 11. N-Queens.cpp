#include<bits/stdc++.h>
using namespace std;
int board[10], cnt;

void print(int n){
    cout<<"\n\nSolution "<<++cnt<<"\n\n";
    for(int i=1; i<=n; i++)
        cout<<"\t"<<i;
    for(int i=1; i<=n; i++){
        cout<<"\n\n"<<i;
        for(int j=1; j<=n; j++){
            if(board[i] == j)
                cout<<"\tQ";
            else
                cout<<"\t-";
        }
    }
}

bool canPlace(int row, int col){
    for(int i=1; i<=row-1; i++){
        if(board[i] == col)// Checking if that column already has a queen.
            return false;
        else if(abs(board[i]-col) == abs(i-row))//Checking if the queens are diagonal to each other.
            return false;
    }
    return true;
}

void nqueens(int row, int n){
    for(int col=1; col<=n; col++){
        if(canPlace(row,col)){
            board[row] = col; // we are storing the columns here
            if(row == n)
                print(n);
            else
                nqueens(row+1, n);
        }
    }
}

int main(){
    cout<<"\nEnter the number of queens::"<<endl;
    int n;  cin>>n;
    if(n<4){
        cout<<"NO SOLUTIONS POSSIBLE"<<endl;
        return 0;
    }
    nqueens(1,n);
    cout<<"\n\nTOTAL "<<cnt<<" SOLUTIONS ARE POSSIBLE\n"<<endl;
    return 0;
/*
        OUTPUT 1

    PS H:\Career> g++ .\Program11Nqueens.cpp
    PS H:\Career> .\a.exe

    Enter the number of queens::
    3
    NO SOLUTIONS POSSIBLE

        OUTPUT 2

    PS H:\Career> .\a.exe
    Enter the number of queens::
    4

    Solution 1

            1       2       3       4

    1       -       Q       -       -

    2       -       -       -       Q

    3       Q       -       -       -

    4       -       -       Q       -

    Solution 2

            1       2       3       4

    1       -       -       Q       -
    2       Q       -       -       -

    3       -       -       -       Q

    4       -       Q       -       -

    TOTAL 2 SOLUTIONS ARE POSSIBLE

        OUTPUT 3

    PS H:\Career> .\a.exe
    Enter the number of queens::
    5

    Solution 1

            1       2       3       4       5

    1       Q       -       -       -       -

    2       -       -       Q       -       -

    3       -       -       -       -       Q

    4       -       Q       -       -       -

    5       -       -       -       Q       -

    Solution 2

            1       2       3       4       5

    1       Q       -       -       -       -

    2       -       -       -       Q       -

    3       -       Q       -       -       -

    4       -       -       -       -       Q

    5       -       -       Q       -       -

    Solution 3

            1       2       3       4       5

    1       -       Q       -       -       -

    2       -       -       -       Q       -

    3       Q       -       -       -       -

    4       -       -       Q       -       -

    5       -       -       -       -       Q

    Solution 4

            1       2       3       4       5

    1       -       Q       -       -       -

    2       -       -       -       -       Q

    3       -       -       Q       -       -

    4       Q       -       -       -       -

    5       -       -       -       Q       -

    Solution 5

            1       2       3       4       5

    1       -       -       Q       -       -

    2       Q       -       -       -       -

    3       -       -       -       Q       -

    4       -       Q       -       -       -

    5       -       -       -       -       Q

    Solution 6

            1       2       3       4       5

    1       -       -       Q       -       -

    2       -       -       -       -       Q

    3       -       Q       -       -       -

    4       -       -       -       Q       -

    5       Q       -       -       -       -

    Solution 7

            1       2       3       4       5

    1       -       -       -       Q       -

    2       Q       -       -       -       -

    3       -       -       Q       -       -

    4       -       -       -       -       Q

    5       -       Q       -       -       -

    Solution 8

            1       2       3       4       5

    1       -       -       -       Q       -

    2       -       Q       -       -       -

    3       -       -       -       -       Q

    4       -       -       Q       -       -

    5       Q       -       -       -       -

    Solution 9

            1       2       3       4       5

    1       -       -       -       -       Q

    2       -       Q       -       -       -

    3       -       -       -       Q       -

    4       Q       -       -       -       -

    5       -       -       Q       -       -

    Solution 10

            1       2       3       4       5

    1       -       -       -       -       Q

    2       -       -       Q       -       -

    3       Q       -       -       -       -

    4       -       -       -       Q       -

    5       -       Q       -       -       -

    TOTAL 10 SOLUTIONS ARE POSSIBLE
*/
}
