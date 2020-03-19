/*





							Name: Gracious Saxena
							USN: 1RV18CS057
							Topic: Tournament Tree






*/

#include <bits/stdc++.h> 
using namespace std; 
  
// Node of the tournament tree 
struct Node { 
    int data; 
    Node *left, *right; 
}; 
  
// To create a new node! 
Node *createNode(int data) { 
    Node *t = new Node; 
    t->left = t->right = NULL; 
    t->data = data; 
    return t; 
} 
  
// It is important to note that root is smallest element of tournament tree. 
// This function traverses tree across height to find second smallest element in tournament tree. 

void traverseHeight(Node *root, int arr[], int &result) { 
    // Base case 
    if (root == NULL || (root->left == NULL && root->right == NULL)) 
        return; 
  
    // If left child is smaller than current resultult ,update resultult and recur for left subarray. 
    if (result > arr[root->left->data] && root->left->data != root->data) { 
        result = arr[root->left->data]; 
        traverseHeight(root->right, arr, result); 
    } 
  
    // If right child is smaller than current resultult ,update resultult and recur for left subarray. 
    else if (result > arr[root->right->data] && 
             root->right->data != root->data) 
    { 
        result = arr[root->right->data]; 
        traverseHeight(root->left, arr, result); 
    } 
} 
  
// Prints minimum and second minimum in arr[0..n-1] 
void findSecondMin(int arr[], int n) { 
    // Create a list to store nodes of current level 
    list<Node *> li; 
  
    Node *root = NULL; 
    for (int i = 0; i < n; i += 2) { 
        Node *t1 = createNode(i); 
        Node *t2 = NULL; 
        if (i + 1 < n) { 
            // Make a node for next element 
            t2 = createNode(i + 1); 
  
            // Make smaller of two as root 
            root = (arr[i] < arr[i + 1])? createNode(i) : 
                                       createNode(i + 1); 
  
            // Make two nodes as children of smaller 
            root->left = t1; 
            root->right = t2; 
  
            // Add root 
            li.push_back(root); 
        } 
        else
            li.push_back(t1); 
    } 
  
    int lsize = li.size(); 
  
    // Construct the complete tournament tree from above prepared list of winners in first round. 
    while (lsize != 1) { 
        // Find index of last pair 
        int last = (lsize & 1)? (lsize - 2) : (lsize - 1); 
  
        // Process current list items in pair 
        for (int i = 0; i < last; i += 2) 
        { 
            // Extract two nodes from list, make a new node for winner of two 
            Node *f1 = li.front(); 
            li.pop_front(); 
  
            Node *f2 = li.front(); 
            li.pop_front(); 
            root = (arr[f1->data] < arr[f2->data])? 
                createNode(f1->data) : createNode(f2->data); 
  
            // Make winner as parent of two 
            root->left = f1; 
            root->right = f2; 
  
            // Add winner to list of next level 
            li.push_back(root); 
        } 
        if (lsize & 1) { 
            li.push_back(li.front()); 
            li.pop_front(); 
        } 
        lsize = li.size(); 
    } 
  
    // Traverse tree from root to find second minimum 
    // Note that minimum is already known and root of 
    // tournament tree. 
    int result = INT_MAX; 
    traverseHeight(root, arr, result); 
    cout << "\n\n\tThe WINNER is:: " << arr[root->data] 
        << "\n\n\tThe RUNNER UP is:: " << result << endl<<"\n\n\tCONGRATULATIONS to all the participants!!!"; 
} 
  
// Driver code 
int main() {
	int temp, arr[100], n;

	cout<<"\n\t"<<"Welcome to the DAA project by Gracious Saxena, 1RV18CS057, B1 Batch!!!"<<"\n\t";
	cout<<"\n\t"<<"Enter the number of participants"<<"\n\t";
	cin>>n;
	cout<<"\n\tEnter the participants, the LESSER number WINS!!!"<<"\n\t";
//	using the bool return from cin to loop.
	for(int i=0; i<n; i++){
		cin>>temp;
		arr[i] = temp;
	}
    // int arr[] = {61, 6, 100, 9, 10, 12, 17};
//	using the sizeof function to calculate the size of the array. 
    // n = sizeof(arr)/sizeof(arr[0]); 
    // cout<<n;
    findSecondMin(arr, n); 
    return 0; 
} 


/*
                    OUTPUT
                    
                    
        Welcome to the DAA project by Gracious Saxena, 1RV18CS057, B1 Batch!!!

        Enter the number of participants
        11

        Enter the participants, the LESSER number WINS!!!
        100 101 102 103 104 105 106 107 108 109 69 876


        The WINNER is:: 69

        The RUNNER UP is:: 100


        CONGRATULATIONS to all the participants!!!
        
*/
