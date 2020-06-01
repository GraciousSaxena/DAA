#include<bits/stdc++.h>

using namespace std;
/*
    OUTPUT 1

PS H:\Career> g++ .\Program10SubsetProblem.cpp
PS H:\Career> .\a.exe
Enter the number of elements in the array::
6
Enter the elements of the array::
4 5 7 2 1 9
Enter the required sum::
9
The required subsets are ::
4 5
7 2
9

    OUTPUT 2
    
PS H:\Career> g++ .\Program10SubsetProblem.cpp
PS H:\Career> .\a.exe
Enter the number of elements in the array::
10
Enter the elements of the array::
1 2 3 4 5 6 7 8 9 10
Enter the required sum::
10
The required subsets are ::
1 2 3 4
1 2 7
1 3 6
1 4 5
1 9
2 3 5
2 8
3 7
4 6
10

*/

void isSum(vector<int> arr, int d){
    int count=0;
    int ans=0;
    vector<int> elements(arr.size(), 0);
    int key=0, prev=key;
    elements[key] = 1;
    cout<<endl;
    while(1){
        if(key<arr.size() && elements[key] == 1){
            if(arr[key] + ans == d){
                // found the solution
                prev = key;
                for(int i=0; i<elements.size(); i++){
                    if(elements[i] == 1){
                        cout<<arr[i]<<" ";
                    }
                }
                // to find other solutions
                elements[key]=0;
                cout<<endl;
                count++;
            }
            else if(arr[key]+ans<d)
                ans+=arr[key];
            else
                elements[key] = 0;
        } else{ // comes here when key goes out of bounds
            key-=1;
            while(key>-1 && elements[key] == 0){
                key--;
            }
            if(key==-1)  break;
            elements[key] = 0;
            ans -= arr[key];
        }
        key+=1;
        elements[key] = 1;
    }
    if(count==0){
        cout<<"No solution is possible."<<endl;
    }
}

int main(){
    cout<<"Enter the number of elements in the array::"<<endl;
    int n;  cin>>n;
    cout<<"Enter the elements of the array::"<<endl;
    vector<int> arr(n);
    int sum=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    cout<<"Enter the required sum::"<<endl;
    int d;  cin>>d;
    if(sum<d){
        cout<<"Solution is NOT possible."<<endl;
        return 0;
    }
    cout<<"The required subsets are ::"<<endl;
    isSum(arr, d);
    return 0;
}
