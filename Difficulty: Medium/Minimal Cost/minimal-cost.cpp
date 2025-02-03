//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[10001];
    
    int help(vector<int>&arr,int index,int k){
        if(index==0)return 0;
        
        if(dp[index]!=-1)return dp[index];
        
        int steps=INT_MAX;
        
        for(int i=1;i<=k;i++){
            if(index-i>=0){
                
            int jump=abs(arr[index]-arr[index-i])+help(arr,index-i,k);
            steps=min(steps,jump);
            }
        }
        return dp[index]=steps;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        memset(dp,-1,sizeof(dp));
        int n=arr.size();
        return help(arr,n-1,k);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends