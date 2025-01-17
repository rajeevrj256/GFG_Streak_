//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>&adj,int V,unordered_map<int,bool>&vis,int node){
        vis[node]=true;
        for(int i=0;i<V;i++){
            if(!vis[i] && adj[node][i]==1){
                dfs(adj,V,vis,i);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        unordered_map<int,bool>vis;
        int cnt=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,V,vis,i);
                cnt++;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends