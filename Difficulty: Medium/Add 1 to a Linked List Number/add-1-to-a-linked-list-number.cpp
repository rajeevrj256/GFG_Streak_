//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

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
   string addnumber(string s,string r){
       string res="";
       int carry=0;
       int i=s.length()-1;
       int j=0;
       
       while(i>=0 || j>=0 || carry){
           int d1=(i>=0?s[i]-'0':0);
           int d2=(j>=0?r[j]-'0':0);
           
           int sum=d1+d2+carry;
           carry=sum/10;
           res+=(sum%10)+'0';
           i--;
           j--;
           
       }
       
       reverse(res.begin(),res.end());
       return res;
       
   }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        string number="";
        Node* curr=head;
        
        while(curr){
            number+=to_string(curr->data);
            curr=curr->next;
        }
        
        string final="";
        final=addnumber(number,"1");
        
        Node* dummy=new Node(0);
        Node* next=dummy;
        
        for(char c:final){
            Node* curr=new Node(c-'0');
            next->next=curr;
            next=next->next;
        }
        
        return dummy->next;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends