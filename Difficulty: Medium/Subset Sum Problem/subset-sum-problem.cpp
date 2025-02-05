//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    
    bool help(vector<int>&arr,int target,int index,vector<vector<int>>&dp){
        if(target==0)return true;
        if(index>=arr.size() || target<0) return false;
       
        
        if(dp[index][target]!=-1)return dp[index][target];
        
        bool take=help(arr,target-arr[index],index+1,dp);
        bool skip=help(arr,target,index+1,dp);
        
        return dp[index][target]=take || skip;
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return help(arr,target,0,dp);
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends