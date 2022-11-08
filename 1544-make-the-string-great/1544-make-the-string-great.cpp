class Solution {
public:
    string makeGood(string s) {
        
        int n=s.length(),p=0;
        for(int i=0;i<n;i++){
            if(p>0&&abs(s[i]-s[p-1])==32)
                p--;
            else
                s[p++]=s[i];
        }
        return s.substr(0,p);
    }
};