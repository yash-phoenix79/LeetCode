class Solution {
public:
    int countAsterisks(string s) {
        
        int res=0;
        bool pres=false;
        int n=s.length();
        
        for(int i=0;i<n;i++){
            if(s[i]=='|')
                pres=!pres;
            if(s[i]=='*'){
                if(!pres)
                    res++;
            }
        }
        return res;
    }
};