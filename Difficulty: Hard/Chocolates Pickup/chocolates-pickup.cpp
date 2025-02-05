//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[71][71][71];
   
    
    int help(int n, int m, vector<vector<int>>& grid,int row,int col1,int col2){
        if(row>=n)return 0;
        if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) return 0; 
        if(dp[row][col1][col2]!=-1)return dp[row][col1][col2];
        
        int chocolates=grid[row][col1];
        
        if(col1!=col2){
            chocolates+=grid[row][col2];
        }
        
        int ans=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int new_row=row+1;
                int new_col1=col1+i;
                int new_col2=col2+j;
                
                    
                ans=max(ans,help(n,m,grid,new_row,new_col1,new_col2));
                
            }
        }
        
        return dp[row][col1][col2]=chocolates+ans;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        memset(dp,-1,sizeof(dp));
        
        return help(n,m,grid,0,0,m-1);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends