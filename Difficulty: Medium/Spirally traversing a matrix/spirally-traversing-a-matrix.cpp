//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int startrow=0;
        int endrow=mat.size()-1;
        
        int startcol=0;
        int endcol=mat[0].size()-1;
        
        vector<int>ans;
        
        while(startrow<=endrow && startcol<=endcol){
            for(int i=startcol;i<=endcol;i++){
                ans.push_back(mat[startrow][i]);
                
            }
            startrow++;
            
            for(int i=startrow;i<=endrow;i++){
                ans.push_back(mat[i][endcol]);
            }
            endcol--;
             
            if(startrow<=endrow){
                
            for(int i=endcol;i>=startcol;i--){
                ans.push_back(mat[endrow][i]);
            }
            endrow--;
            }   
            
            
            if(startcol<=endcol){
                
            for(int i=endrow;i>=startrow;i--){
                ans.push_back(mat[i][startcol]);
            }
            startcol++;
            }
            
            
                
            
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends