//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool check(vector<int>&arr,int k, int distance){
        int cow=1;
        int lastpos=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-lastpos>=distance){
                cow++;
                lastpos=arr[i];
                if(cow>=k) return true;
            }
        }
        
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        
        sort(stalls.begin(),stalls.end());
        int s=1;
        int e=stalls[stalls.size()-1]-stalls[0];
        int ans=0;
        while(s<=e){
            int mid=(s+e)/2;
            if(check(stalls,k,mid)){
                s=mid+1;
                ans=mid;
                
            }else {
                e=mid-1;
        }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends