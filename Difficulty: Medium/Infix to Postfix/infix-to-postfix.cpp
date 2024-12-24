//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int precedence(char c){
        if(c=='^')return 3;
        else if(c=='*' || c=='/')return 2;
        else if(c=='+' || c=='-') return 1;
        
        return 0;
    }
    string infixToPostfix(string& s) {
        // Your code here
        string postfix="";
        stack <char>st;
        for(char c:s){
            if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
                postfix+=c;
                
            }else if(c=='('){
                st.push('(');
            }else if(c==')' ){
                while(st.top()!='('){
                    
                postfix+=st.top();
                st.pop();
                }
                st.pop();
            }else{
                while(!st.empty() && precedence(c)<=precedence(st.top())){
                    postfix+=st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        
        while(!st.empty()){
            postfix+=st.top();
            st.pop();
        }
        
        return postfix;
        
    }
};


//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends