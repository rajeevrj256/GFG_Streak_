class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        queue<int>q;
        q.push(0);
        vector<int>ans;
        int n=adj.size();
        vector<int>vis(n,0);
        vis[0]=1;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            ans.push_back(top);
            for(auto i:adj[top]){
                if(!vis[i]){
                    vis[i]=1;
                q.push(i);
                }
            }
        }
        return ans;
    }
};