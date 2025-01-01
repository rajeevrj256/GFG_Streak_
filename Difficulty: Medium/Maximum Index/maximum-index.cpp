//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int maxIndexDiff(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        vector<int>left(n);
        left[0]=arr[0];
        
        for(int i=1;i<n;i++){
            left[i]=min(left[i-1],arr[i]);
        }
        
        vector<int>right(n);
        right[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],arr[i]);
        }
        
        int ans=0;
        
        int i=0;
        int j=0;
        
        while(i<n && j<n){
            if(left[i]<=right[j]){
                ans=max(ans,j-i);
                j++;
            }else{
                i++;
            }
        }
        
        return ans;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(arr);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends