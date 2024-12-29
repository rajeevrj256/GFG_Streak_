//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
            unordered_map<int,int>hash;
            vector<int>sorted=arr;
            sort(sorted.begin(),sorted.end());
            int index=1;
            for(int i =0;i<arr.size();i++){
                if(hash.find(sorted[i])==hash.end()){
                    hash[sorted[i]]=index;
                    index++;
                }
                
                
            }
            
            for(int i=0;i<arr.size();i++){
                arr[i]=hash[arr[i]];
            }
            
            return arr;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends