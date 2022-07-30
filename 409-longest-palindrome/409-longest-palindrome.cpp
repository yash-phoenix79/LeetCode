class Solution {
public:
    int longestPalindrome(string s) {
        
        int n=s.length();
        
        vector<int>up(26,0),lo(26,0);
        
        for(int i=0;i<n;i++){
            if(isupper(s[i]))
            up[s[i]-'A']++;
            else
                lo[s[i]-'a']++;
        }
        
        bool check=false;
        
        int res=0;
        for(int i=0;i<26;i++){
            int t1,t2;
            t1=up[i]/2;
            t2=lo[i]/2;
            res+=(t1*2+t2*2);
            if(lo[i]%2||up[i]%2)
                check=true;
        }
        
        if(check)
            res++;
        return res;
    }
};