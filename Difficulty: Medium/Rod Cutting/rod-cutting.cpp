//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int t[1001];
  
    int solve(vector<int>&price,int index){
        if(index==0){
            return 0;
            
        }
        
        if(t[index]!=-1)return t[index];
        int maxprofit=0;
        for(int i=1;i<=index;i++){
            maxprofit=max(maxprofit,price[i-1]+solve(price,index-i));
        }
        
        
        
        return t[index]=maxprofit;
    }
    int cutRod(vector<int> &price) {
        // code here
        memset(t,-1,sizeof(t));
        return solve(price,price.size());
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends