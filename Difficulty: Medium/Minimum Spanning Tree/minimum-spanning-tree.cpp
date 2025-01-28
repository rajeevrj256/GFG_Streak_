//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
       
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<bool>vis(V,false);
        
        //vis[0]=true;
        q.push({0,0});
        int sum=0;
        while(!q.empty()){
            int dist=q.top().first;
            int node=q.top().second;
            q.pop();
            
            if(vis[node])continue;
            vis[node]=true;
            
            sum+=dist;
            
            for(auto neighbor:adj[node]){
                int nextNode = neighbor[0];
                int edgeWeight = neighbor[1];
                if(!vis[nextNode]){
                    q.push({edgeWeight,nextNode});
                }
            }
        }
        
        return sum;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends