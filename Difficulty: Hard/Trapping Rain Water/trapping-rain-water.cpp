//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long maxWater(vector<int>&arr){
        // code here
        int n=arr.size();
        vector<long long>dp(n,0);
        int l=0;
        int r=n-1;
        int left=arr[0];
        int right=arr[n-1];
        int i=1;
        dp[0]=0;
        //int water=0;
        while(l<r){
            if(left<right){
                l++;
                left=max(left,arr[l]);
                dp[i]=dp[i-1]+left-arr[l];
                //water+=left-arr[l];
                
            }else{
                r--;
                right=max(right,arr[r]);
                dp[i]=dp[i-1]+right-arr[r];
                //water+=right-arr[r];
            }
            i++;
        }
        return dp[n-1];
        
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends