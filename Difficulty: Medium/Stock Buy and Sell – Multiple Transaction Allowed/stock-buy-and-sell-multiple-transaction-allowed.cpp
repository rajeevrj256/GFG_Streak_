
class Solution {
  public:
  
    int solve(vector<int>&prices, vector<vector<int>>&dp,int index,int action){
        if(index>=prices.size()) return 0;
        
        
        if(dp[index][action]!=-1) return dp[index][action];
        int skip=solve(prices,dp,index+1,action);
        int take=0;
        if(action==0){
            take=-prices[index]+solve(prices,dp,index+1,!action);
        }else{
            take=prices[index]+solve(prices,dp,index+1,!action);
        }
        
        return dp[index][action] =max(skip,take);
    }
    int maximumProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,dp,0,0);
        
    }
};
