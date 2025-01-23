//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        
        for(auto edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        
        vector<int>ans(V,INT_MAX);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>q;
        
        q.push({0,0});
        ans[0]=0;
        
        while(!q.empty()){
            int node=q.top().second;
            int step=q.top().first;
            q.pop();
            
            
            for(auto neighbor:adj[node]){
                   int nextNode = neighbor.first;
                  int edgeWeight = neighbor.second;
                   if(step+edgeWeight<ans[nextNode]){
                       ans[nextNode]=step+neighbor.second;
                       
                    q.push({step+neighbor.second,neighbor.first});
                   }
                
                  
                
            }
            
        }
        for(int i=0;i<V;i++){
            if(ans[i]==INT_MAX) ans[i]=-1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends