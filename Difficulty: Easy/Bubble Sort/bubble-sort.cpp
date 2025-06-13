class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int>& arr) {
        // Your code here
        for(int i=0;i<arr.size()-1;i++){
            bool swaped=false;
            
            for(int j=0;j<arr.size()-i-1;j++){
                  if(arr[j]>arr[j+1]){
                      swap(arr[j],arr[j+1]);
                      swaped=true;
                  }
            }
            
            if(!swaped) break;
        }
    }
};