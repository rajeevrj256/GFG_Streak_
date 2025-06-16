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
  int count = 0;
    int result = -1;

    void reverseInorder(Node* root,int k){
        if(root==NULL || count>=k) return ;
        reverseInorder(root->right,k);
        count++;
        if(count==k){
            result=root->data;
            return;
        }
        
        reverseInorder(root->left,k);
    }
    int kthLargest(Node *root, int k) {
        // Your code here
        
         count = 0;
        result = -1;
        reverseInorder(root, k);
        return result;
        
        
    }
};