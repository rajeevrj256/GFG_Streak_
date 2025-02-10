//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int help(vector<int>&val,vector<int>&wt,vector<vector<int>>&dp,int index,int target){
        if(index==0){
            return (target / wt[0]) * val[0];
        }
        
        if(dp[index][target]!=-1)return dp[index][target];
        
        int skip=help(val,wt,dp,index-1,target);
        int take=0;
        if(wt[index]<=target){
            take=val[index]+help(val,wt,dp,index,target-wt[index]);
        }
        
        return dp[index][target]=max(skip,take);
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=wt.size();
        //vector<vector<int>>dp(n,vector<int>(capacity+1,0));
        vector<int>dp(capacity+1,0);
        
        for(int i=0;i<=capacity;i++){
            dp[i]=(i/wt[0])*val[0];
        }
        
        for(int i=1;i<n;i++){
           // vector<int>curr(capacity+1,0);
            for(int j=0;j<=capacity;j++){
                int skip=dp[j];
                int take=0;
                
                if(wt[i]<=j){
                    take=val[i]+dp[j-wt[i]];
                }
                
                dp[j]=max(skip,take);
            }
           // dp=curr;
            
        }
        
        return dp[capacity];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends