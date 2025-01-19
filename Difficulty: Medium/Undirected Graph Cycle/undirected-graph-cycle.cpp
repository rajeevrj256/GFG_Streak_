//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cyclic(vector<vector<int>>&adj,unordered_map<int,bool>&vis,unordered_map<int,int>&parent,int node){
        vis[node]=true;
        queue<int>q;
        q.push(node);
        parent[node]=-1;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            
            for(int neighbor:adj[temp]){
                if(vis[neighbor] && parent[temp]!=neighbor){
                    return true;
                }else if(!vis[neighbor]){
                    q.push(neighbor);
                    vis[neighbor]=true;
                    parent[neighbor]=temp;
                }
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int,bool>vis;
        unordered_map<int,int>parent;
        
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                bool ans=cyclic(adj,vis,parent,i);
                if(ans==true)
                return true;
            }
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends