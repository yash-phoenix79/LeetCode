class Solution {
public:
    string shortestPalindrome(string s) {
        int l=s.length();
        if(l==0)
            return "";
        if(l==1)
            return s;
        
        string t=s,y=s;
        reverse(s.begin(),s.end());
        if(s==y)
            return s;
        t=t+"#"+s;
        
        int n=t.length();
        vector<int>pref(n);
        pref[0]=0;
        int i=0,j=1;
        
        while(j<n){
            i=pref[j-1];
            while(i!=0&&t[i]!=t[j])
                i=pref[i-1];
            if(t[j]==t[i]){
                pref[j]=i+1;
               
                j++;
            }
            else{
                pref[j]=0;
                j++;
            }
        }
        
        int x=pref[n-1];
        if(x==l)
            return y;
        string res=t.substr(x,l-x);
        reverse(res.begin(),res.end());
        return res+y;
        
    }
};