class Solution {
public:
    int countSubstrings(string s) {
        
        int n=s.length(),ans=0;
        
        int idx=0;
        
        while(idx<n){
            int left=idx,right=idx;
            while(left>=0&&right<n&&s[left--]==s[right++]){
                 ans++;
                
            }
             idx++;  
        }
        idx=1;
        while(idx<n){
            int left=idx-1,right=idx;
            while(left>=0&&right<n&&s[left--]==s[right++])
                ans++;
            idx++;
        }
        
        return ans;
        
    }
};