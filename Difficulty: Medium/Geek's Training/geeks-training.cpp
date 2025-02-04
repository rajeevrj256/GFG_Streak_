//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int t[100001][3];
    int help(vector<vector<int>>& arr,int activity,int day){
        if(day==arr.size())return 0;
        
        if(t[day][activity]!=-1)return t[day][activity];
        
        int sport1=0;
        int sport2=0;
        int sport3=0;
        
        if(activity==0){
            sport1=arr[day][0]+max(help(arr,1,day+1),help(arr,2,day+1));
            
        }
        
        if(activity==1){
            sport2=arr[day][1]+max(help(arr,0,day+1),help(arr,2,day+1));
        }
        
        if(activity==2){
            sport2=arr[day][2]+max(help(arr,0,day+1),help(arr,1,day+1));
        }
        
        return t[day][activity]=max({sport1,sport2,sport3});
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        memset(t,-1,sizeof(t));
        
        return max({help(arr,0,0),help(arr,1,0),help(arr,2,0)});
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends