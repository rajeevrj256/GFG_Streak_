//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int N)  
{
    // code here
    int xorr = 0;
    for (int i = 0; i < N; i++) {
        xorr ^= arr[i];
    }

    int rightmost = xorr & -xorr;

    long long int b1 = 0, b2 = 0;

    for (int i = 0; i < N; i++) {
        if ((arr[i] & rightmost) != 0) {
            b1 ^= arr[i];
        } else {
            b2 ^= arr[i];
        }
    }

    // Use a vector to return the two numbers
    vector<long long int> result;
    if (b1 > b2) {
        result.push_back(b1);
        result.push_back(b2);
    } else {
        result.push_back(b2);
        result.push_back(b1);
    }

    return result;


    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends