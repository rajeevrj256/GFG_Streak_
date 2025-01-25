//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        if (start == end) return 0;

        queue<pair<int,int>>q;
        q.push({0,start});
        
        vector<int>dist(100000,INT_MAX);
        dist[start]=0;
        
        int mod=100000;
        while(!q.empty()){
           int step=q.front().first;
           int node=q.front().second;
            q.pop();
            
            for(auto it:arr){
                
                int num=(it*node)%mod;
                if(step+1<dist[num]){
                    
                    dist[num]=step+1;
                    
                    
                
                if(num==end){
                    return step+1;
                    
                }
                
                q.push({step+1,num});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends