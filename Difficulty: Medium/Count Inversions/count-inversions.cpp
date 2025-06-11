class Solution {
  public:
    // Function to count inversions in the array.
    int merge(vector<int>&arr,int start,int mid,int end){
        vector<int>temp;
        
        int left=start;
        int right=mid+1;
        int cnt=0;
        
        while(left<=mid && right<=end){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                cnt+=(mid-left+1);
                right++;
            }
        }
        
        while(left<=mid){
            temp.push_back(arr[left]);
                left++;
        }
        
        while(right<=end){
             temp.push_back(arr[right]);
                
                right++;
        }
        
          for (int i = 0; i < temp.size(); ++i) {
            arr[start + i] = temp[i];
        }

        
        return cnt;
    }
    
    int mergeSort(vector<int>&arr,int start,int end){
        int mid=(start+end)/2;
        int cnt=0;
        
        if(start>=end) return cnt;
        
        cnt+=mergeSort(arr,start,mid);
        cnt+=mergeSort(arr,mid+1,end);
        cnt+=merge(arr,start,mid,end);
        
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
       return  mergeSort(arr,0,arr.size()-1);
    }
};