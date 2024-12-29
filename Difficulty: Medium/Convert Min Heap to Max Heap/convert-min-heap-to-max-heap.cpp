//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void maxheapify(vector<int>&arr,int n,int i){
        int largest_index=i;
        int left_child=2*i+1;
        int right_child=2*i+2;
        
        if(left_child<n && arr[largest_index]<arr[left_child]){
            largest_index=left_child;
        }
        
        if(right_child<n && arr[largest_index]<arr[right_child]){
            largest_index=right_child;
        }
        
        if(i!=largest_index){
            swap(arr[largest_index],arr[i]);
            maxheapify(arr,n,largest_index);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int N){
         for(int i=(N/2)-1;i>=0;i--){
             maxheapify(arr,N,i);
         }
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
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends