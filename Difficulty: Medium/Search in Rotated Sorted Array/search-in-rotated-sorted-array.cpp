//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int n=arr.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            
            int mid=(i+j)/2;
            if(arr[mid]==key){
                return mid;
            } 
            
            if(arr[i]<=arr[mid]){
                if(key>=arr[i] && key<arr[mid]){
                    j=mid-1;
                }else{
                    i=mid+1;
                }
            }else{
                if(key>arr[mid] && key<=arr[j]){
                    i=mid+1;
                    
                }else{
                    j=mid-1;
                }
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends