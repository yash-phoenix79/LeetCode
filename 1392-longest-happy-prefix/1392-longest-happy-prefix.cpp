class Solution {
public:
    string longestPrefix(string s) {
        
        int n=s.length();
        if(n==1)
            return "";
        vector<int>pref(n);
        pref[0]=0;
        
        int i=0,j=1;
        for( j=1;j<n;j++){
            while(i!=0&&s[j]!=s[i])
                i=pref[i-1];
            if(s[j]==s[i]){
                 pref[j]=i+1;
                i++;
            }
            else
                pref[j]=0;
               
        }
        
        return s.substr(0,pref[n-1]);
        
    }
};