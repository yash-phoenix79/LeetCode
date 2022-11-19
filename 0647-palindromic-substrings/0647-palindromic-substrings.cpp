class Solution {
public:
    int countSubstrings(string s) {
        
        int n=s.length();
        
        int res=0;
        
        int idx=0,l,r;
        
        while(idx<n){
            
            l=idx,r=idx;
            while(l>=0&&r<n&&s[l--]==s[r++])
                res++;
            idx++;
            
        }
        
        idx=1;
        while(idx<n){
            l=idx-1,r=idx;
            while(l>=0&&r<n&&s[l--]==s[r++])
                res++;
            idx++;
        }
        return res;
        
    }
};