//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solve(vector<int>&arr,vector<vector<int>>&dp,int index,int target){
        if(index==0){
            
        if(target==0 && arr[0]==0){
            return 2;
        }
        
        if(target==0 || arr[0]==target) return 1;
        
        return 0;
        
        }
        
        if(index>=arr.size() || target<0)return 0;
        
        if(dp[index][target]!=-1)return dp[index][target];
        
        int skip=solve(arr,dp,index-1,target);
        
        int take=0;
        if(arr[index]<=target){
            
         take=solve(arr,dp,index-1,target-arr[index]);
        }
        
        return dp[index][target]=take+skip;
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int totalSum=0;
        for(int num:arr){
            totalSum+=num;
        }
        
        if ((totalSum - d) < 0 || (totalSum - d) % 2 != 0) {
        return 0;
    }
        int target=(totalSum-d)/2;
        
        
        
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
    
        return solve(arr,dp,n-1,target);
        
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends