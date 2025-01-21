//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    vector<int>topsort(vector<vector<int>>&adj,int k){
        vector<int>indegree(k,0);
        for(int i=0;i<k;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<k;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            
            
        }
        
        return ans;
    }
    string findOrder(vector<string> dict, int k) {
        // code here
        vector<vector<int>>adj(k);
        
        for(int i=0;i<dict.size()-1;i++){
            string word1=dict[i];
            string word2=dict[i+1];
            
            int len=min(word1.size(),word2.size());
            for(int j=0;j<len;j++){
                if(word1[j]!=word2[j]){
                    
                adj[word1[j]-'a'].push_back(word2[j]-'a');
                break;
                }
            }
        }
        
        vector<int>ans=topsort(adj,k);
        if (ans.size() < k) {
            return "";
        }

        string res="";
        for(auto it:ans){
            res=res+char(it+'a');
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            a.push_back(number);
        }
        int K;
        cin >> K;
        getchar();
        Solution obj;
        string ans = obj.findOrder(a, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[a.size()];
        std::copy(a.begin(), a.end(), temp);
        sort(temp, temp + a.size(), f);

        bool f = true;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != temp[i])
                f = false;

        if (f)
            cout << "true";
        else
            cout << "false";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends