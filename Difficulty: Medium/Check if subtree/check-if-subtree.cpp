/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    // Function to check if S is a subtree of tree T.
    bool identical(Node*T,Node*S){
        if(T==NULL && S==NULL) return true ;
        
        if(T==NULL || S==NULL) return false;
        
        
        return (T->data==S->data) && (identical(T->left,S->left) && identical(T->right,S->right));
    };
    bool isSubTree(Node* T, Node* S) {
        // Your code here
        if(T==NULL && S==NULL) return true ;
        
        if(T==NULL || S==NULL) return false;
        
        if(identical(T,S)) return true;
        
        return isSubTree(T->left,S ) || isSubTree(T->right,S);
    }
};