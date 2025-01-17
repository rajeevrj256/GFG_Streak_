//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(vector<int>&ans,vector<vector<int>>&adj,int node,unordered_map<int,bool>&vis){
        vis[node]=true;
        ans.push_back(node);
        
        for(auto neighbor:adj[node]){
            if(!vis[neighbor]){
                dfs(ans,adj,neighbor,vis);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int,bool>vis;
        vector<int>ans;
        dfs(ans,adj,0,vis);
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends