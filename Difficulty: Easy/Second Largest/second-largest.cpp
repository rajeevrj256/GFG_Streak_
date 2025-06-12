class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest=arr[0];
        int sec=INT_MIN;
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(largest<arr[i]){
                sec=largest;
                largest=arr[i];
            }
            
            if(sec<arr[i]){
                if(arr[i]<largest){
                    sec=arr[i];
                }
            }
        }
        
        return sec<=0?-1:sec;
    }
};