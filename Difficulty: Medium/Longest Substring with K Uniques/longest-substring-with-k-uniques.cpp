// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        int i=0;
        int j=0;
        int len=-1;
        unordered_map<char,int>hash;
        
        while(j<s.size()){
            hash[s[j]]++;
            
            while(i<s.size() && hash.size()>k){
                hash[s[i]]--;
                if(hash[s[i]]==0){
                    hash.erase(s[i]);
                }
                i++;
            }
            
            if(hash.size()==k) len=max(len,j-i+1);
            
            j++;
            
        }
        
        return len;
    }
};