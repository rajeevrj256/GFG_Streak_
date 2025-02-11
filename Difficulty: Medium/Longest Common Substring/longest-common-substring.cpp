//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int help(string s,int ind1,string t,int ind2,vector<vector<int>>&dp,int &maxlength){
        if(ind1<0 || ind2<0) return 0;
        
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        
        if(s[ind1]==t[ind2]){
            dp[ind1][ind2]=1+help(s,ind1-1,t,ind2-1,dp,maxlength);
            maxlength=max(maxlength,dp[ind1][ind2]);
        }else if(s[ind1]!=s[ind2]){
            return dp[ind1][ind2]=0;
        }
    }
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n=s1.size();
        int m=s2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int maxlength=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    maxlength=max(maxlength,dp[i][j]);
                }else{
                    dp[i][j]=0;
                }
            }
        }
        
        return maxlength;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends