class Solution {
  public:
    int mod=100000007;
    int maxValue(vector<int> &arr) {
        // Complete the function
        sort(arr.begin(),arr.end());
        int mod=1e9+7;
        int j=0;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum=(sum+(long)i*arr[i])%mod;
            
        }
        return sum;
    }
};