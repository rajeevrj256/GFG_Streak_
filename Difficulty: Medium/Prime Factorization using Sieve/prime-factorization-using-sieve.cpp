//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int n) {

        // Write your code here
        vector<bool>isprime(n+1,true);
        isprime[0] = isprime[1] = false;
        
        for(int i=2;i*i<=n;i++){
              
              if(isprime[i]){
               
                for(int j=i*i;j<=n;j+=i){
                   isprime[j]=false;
                }
              }
        }
        
        vector<int> factors;
        for(int i = 2; i * i <= n; i++) {
            while(n % i == 0 && isprime[i]) {
                factors.push_back(i);
                n = n / i;
            }
        }
        if(n > 1)
            factors.push_back(n);
        //delete[] isprime;
        return factors;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends