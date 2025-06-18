
stack<int>minS;

void push(stack<int>& s, int a) {
    // Your code goes here
    s.push(a);
    
    if (minS.empty() || a <= minS.top()) {
        minS.push(a);
    }
    
}

bool isFull(stack<int>& s, int n) {
    // Your code goes here
    
    return s.size()==n;
}

bool isEmpty(stack<int>& s) {
    // Your code goes here
    return s.size()==0;
}

int pop(stack<int>& s) {
    // Your code goes here
    
    if(s.empty()) return -1;
    

    
       int  topVal=s.top();
        s.pop();
      
    
    
    if(!minS.empty() && topVal==minS.top()){
        minS.pop();
    }
    
    return topVal;
    
}

int getMin(stack<int>& s) {
    // Your code goes here.
    if(!minS.empty()) return minS.top();
    
    return -1;
}