//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DSU{
    public:
    vector<int>rank,parent;
    
    DSU(int n){
       rank.resize(n,0);
       parent.resize(n);
       for(int i=0;i<n;i++){
           parent[i]=i;
       }
       
    }
    
    int find(int node){
        if(node==parent[node])return node;
        
        return parent[node]=find(parent[node]);
    }
    
    
    void unionSet(int u,int v){
        int find_u=find(u);
        int find_v=find(v);
        
        if(find_u==find_v)return;
        
        if(rank[find_u]>rank[find_v]){
            parent[find_v]=find_u;
        }else if(rank[find_v]>rank[find_u]){
            parent[find_u]=find_v;
        }else{
            parent[find_u]=find_v;
            rank[find_v]++;
        }
    }
};


class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                
            edges.push_back({it[1],{i,it[0]}});
            
            }
        }
        
        sort(edges.begin(),edges.end());
        
        DSU ds(V);
        
        int sum=0;
        
        for(auto it:edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            if(ds.find(u)!=ds.find(v)){
                sum+=wt;
                ds.unionSet(u,v);
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