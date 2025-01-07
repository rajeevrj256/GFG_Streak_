//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    // Function to check whether all nodes of a tree satisfy the sum property
    bool check(Node* root) {
        if (root == NULL) return true;  // Base case: empty tree is trivially valid

        // If node is a leaf, it satisfies the sum property (no children)
        if (root->left == NULL && root->right == NULL) return true;

        int leftData = 0, rightData = 0;

        // If left child exists, get its data
        if (root->left != NULL) leftData = root->left->data;

        // If right child exists, get its data
        if (root->right != NULL) rightData = root->right->data;

        // Check if current node's value equals the sum of its children
        if (root->data != leftData + rightData) return false;

        // Recursively check left and right subtrees
        return check(root->left) && check(root->right);
    }

    int isSumProperty(Node *root) {
        if (root == NULL) return 1;  // Empty tree satisfies sum property by definition
        return check(root) ? 1 : 0;  // Return 1 if sum property holds, otherwise 0
    }

};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isSumProperty(root) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends