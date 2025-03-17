//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> toposort(vector<vector<int>>& adj, vector<int>& indegree, unordered_set<int>& present) {
        queue<int> q;
        vector<int> ans;

        // Push nodes with in-degree 0 into the queue
        for (int ch : present) {
            if (indegree[ch] == 0) {
                q.push(ch);
            }
        }

        while (!q.empty()) {
            int top = q.front();
            q.pop();
            ans.push_back(top);

            for (int neighbor : adj[top]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Check if a valid topological order is found
        if (ans.size() != present.size()) return {}; // Cycle detected

        return ans;
    }

    string findOrder(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        unordered_set<int> present; // To track present characters

        // Mark all characters present in input
        for (string& word : words) {
            for (char ch : word) {
                present.insert(ch - 'a');
            }
        }

        // Build the graph
        for (int i = 0; i < n - 1; i++) {
            string& s1 = words[i];
            string& s2 = words[i + 1];

            int len = min(s1.length(), s2.length());
            bool foundDifference = false;

            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    indegree[s2[j] - 'a']++;
                    foundDifference = true;
                    break;
                }
            }

            // Handle invalid case: if s2 is a prefix of s1, return ""
            if (!foundDifference && s1.length() > s2.length()) return "";
        }

        // Get topological order
        vector<int> order = toposort(adj, indegree, present);
        if (order.empty()) return ""; // Cycle detected

        string res = "";
        for (int num : order) {
            res += (num + 'a');
        }

        return res;
    }
};



//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends