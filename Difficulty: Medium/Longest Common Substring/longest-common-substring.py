#User function Template for python3

class Solution:
    def longestCommonSubstr(self, s1, s2):
        # code here
        n=len(s1)
        m=len(s2)
        
        #dp = [[0] * (m + 1) for _ in range(n + 1)]
        dp=[[0]*(m+1) for _ in range(n+1)]
        
        maxlength=0;
        
        for i in range (1,n+1):
            for j in range(1,m+1):
                if s1[i-1]==s2[j-1]:
                    dp[i][j]=1+dp[i-1][j-1]
                    maxlength=max(maxlength,dp[i][j])
                else:
                    dp[i][j]=0
        
        
        return maxlength
                    
                


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        S1 = input().strip()
        S2 = input().strip()
        ob = Solution()
        print(ob.longestCommonSubstr(S1, S2))
        print("~")

# } Driver Code Ends