/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Should return head of the modified linked list
    Node* sortedInsert(Node* head, int key) {
        // Code here
         Node* newHead=new Node(key);
        Node* prev=NULL;
        Node* curr=head;
        if(head ==NULL || head->data>=key){
           
            newHead->next=head;
            
            return newHead;
        }
        while(curr->next!=NULL && curr->next->data <key){
            
            curr=curr->next;
        }
        newHead->next=curr->next;
        
        curr->next=newHead;
        
        return head;
    }
};