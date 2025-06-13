class Solution {
  public:
    Solution() {
        // code here
        
        
    }
    
    int mini=INT_MAX;
    stack<pair<int,int>>s;

    // Add an element to the top of Stack
    void push(int x) {
        
        // code here
        mini=min(mini,x);
        s.push({x,mini});
        
        
    }

    // Remove the top element from the Stack
        
    void pop() {
        // code here
        
        if(!s.empty()){
            
            s.pop();
            
            if(!s.empty()){
             auto first=s.top();
            mini=first.second;    
            }else{
                mini=INT_MAX;
            }
            
        }
    }

        
    // Returns top element of the Stack
    int peek() {
        // code here
        int top=-1;
        if(!s.empty()){
            auto first=s.top();
            top=first.first;
        }
        
        return top;
    }
        

    // Finds minimum element of Stack
    int getMin() {
        // code here
        return mini==INT_MAX?-1:mini;
        
        
    }
};