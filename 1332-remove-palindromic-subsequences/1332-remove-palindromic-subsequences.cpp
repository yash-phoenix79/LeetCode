class Solution {
public:
    int removePalindromeSub(string s) {
        int i=0;
        int n=s.size();
        
        while(i<n/2){
            if(s[i]!=s[n-i-1])
                break;
            i++;
        }
        
        if(i==n/2)
            return 1;
    
        return 2;
        
    }
};