/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    void solve(Node* root,priority_queue<int>&maxheap){
        if(root==NULL) return;
        
        maxheap.push(root->data);
        solve(root->left,maxheap);
        solve(root->right,maxheap);
    }
    int kthLargest(Node *root, int k) {
        // Your code here
        
        if(root==NULL) return 0;
        priority_queue<int>maxheap;
        
        Node* temp=root;
        
        solve(temp,maxheap);
        
        while(k>1 && !maxheap.empty()){
            maxheap.pop();
            k--;
        }
        
        return maxheap.empty()?0:maxheap.top();
        
    }
};