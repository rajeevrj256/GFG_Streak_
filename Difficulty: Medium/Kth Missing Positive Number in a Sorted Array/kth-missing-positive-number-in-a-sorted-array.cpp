//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        unordered_map<int,bool>hash;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        
        for(int num:arr){
            hash[num]=true;
            mini=min(mini,num);
            maxi=max(maxi,num);
            
        
        }
        
        if(mini>1){
            mini=1;
        }
        int cnt=0;
        for(int i=mini;i<INT_MAX;i++){
            if(!hash[i]){
                cnt++;
                
            }
            if(cnt==k){
                return i;
            }
                
        }
        return -1;

            
        
            
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
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends