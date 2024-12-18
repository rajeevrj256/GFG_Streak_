//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(vector<int>&arr,int k,int pages){
        
        int student=1;
        int page=0;
        
        for(int i=0;i<arr.size();i++){
            if (arr[i] > pages) {
            return false;
        }
            if(page+arr[i]<=pages){
                
                page+=arr[i];
            }else{
                student++;
                page=arr[i];
                if(student>k){
                    return false;
                }
            }
            
        }
        
        return true;
        
    }
    int findPages(vector<int> &arr, int k) {
        // code here
       
        int n=arr.size();
        
        if (n < k) {
        return -1; // Not enough books for the students
    }
        int sum=0;
        int maxElement=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
             maxElement = max(maxElement, arr[i]);
        }
         int s=maxElement;
        int e=sum;
        int ans=INT_MAX;
        while(s<=e){
            int mid=(s+e)/2;
            
            if(check(arr,k,mid)){
                ans=min(ans,mid);
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans==0?-1:ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends