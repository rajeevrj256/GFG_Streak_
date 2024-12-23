//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(int r){
        if(r%4==0)return r;
        else if(r%4==1) return 1;
        else if(r%4==2) return r+1;
        
        return 0;
    }
    int findXOR(int l, int r) {
        // complete the function here
        return f(l-1)^f(r);
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends