class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        sort(arr, arr + n);
        long long count=0;
        for(int k=0;k<n-2;k++){
            int i=k+1;
            int j=n-1;
            
            
            while(i<j){
                int tempsum=arr[k]+arr[i]+arr[j];
                
                if(tempsum<sum){
                    count+=(j-i);     
                    i++;
                }else{
                    j--;
                }
            }
        }
        return count;
    }
};