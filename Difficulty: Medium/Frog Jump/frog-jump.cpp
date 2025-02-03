//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[100001];
    int help(vector<int>&height,int step){
        if(step==0) return 0;
        
        if(dp[step]!=-1)return dp[step];
        
        int onestep=help(height,step-1)+abs(height[step]-height[step-1]);
        int twostep=INT_MAX;
        if(step>1){
            
        twostep=help(height,step-2)+abs(height[step]-height[step-2]);
        }
        
        return dp[step]=min(onestep,twostep);
        
    }
    int minCost(vector<int>& height) {
        // Code here
        memset(dp,-1,sizeof(dp));
        int n=height.size();
        return help(height,n-1);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends