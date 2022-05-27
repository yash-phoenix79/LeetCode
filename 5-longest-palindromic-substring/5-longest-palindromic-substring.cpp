class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int n=s.length();
        
      
        
        int len=0,maxLen=0;
        int l,r;
        for(int i=0;i<n;i++){
            l=i-1,r=i+1,len=1;
            while(l>=0&&r<n&&s[l]==s[r]){
                len+=2;
                l--,r++;
            }
            if(len>maxLen){
                 maxLen=len;
                res=s.substr(l+1,maxLen);
            }
               
        }
        
        for(int i=1;i<n;i++){
            l=i-1,r=i,len=0;
            while(l>=0&&r<n&&s[l]==s[r]){
                 len+=2;
                 l--,r++;
            }
            if(len>maxLen){
                 maxLen=len;
                res=s.substr(l+1,maxLen);
            }
               
        }
        
        
        return res;
        
    }
};