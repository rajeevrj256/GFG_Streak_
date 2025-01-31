//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int i=0;
        int j=0;
        int prefixsum=0;
        while(i<arr.size() && j<arr.size()){
            prefixsum+=arr[j];
            
            while(prefixsum>target && i<j){
                prefixsum-=arr[i];
                i++;
                //if(i==target)return {i,i};
            }
            if(prefixsum==target){
                return {i+1,j+1};
            }
            j++;
        }
        
        return {-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends