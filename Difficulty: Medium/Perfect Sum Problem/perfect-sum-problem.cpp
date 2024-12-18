//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int t[1000][1000];
    int help(vector<int>&arr,int target,int index){
        
        if(index>=arr.size()){
            return target==0;
        }
        if (index >= arr.size() || target < 0) {
        return 0; // No valid subset.
    }

        if(t[index][target]!=-1)return t[index][target];
        
        int ans=help(arr,target,index+1);
        
        if(arr[index]<=target){
            
         ans+=help(arr,target-arr[index],index+1);
        }
        
        return t[index][target]=ans;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        memset(t,-1,sizeof(t));
        return help(arr,target,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends