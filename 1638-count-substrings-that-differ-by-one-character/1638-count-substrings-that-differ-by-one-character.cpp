class Solution {
public:
    int countSubstrings(string s, string t) {
        
        int res=0,miss=0;
        
        for(int i=0;i<s.length();i++){
            for(int j=0;j<t.length();j++){
                miss=0;
                for(int pos=0;pos+i<s.length()&&pos+j<t.length();pos++){
                    if(s[i+pos]!=t[j+pos]&&++miss>1)
                        break;
                    res+=miss;
                }
            }
        }
        return res;
    }
};