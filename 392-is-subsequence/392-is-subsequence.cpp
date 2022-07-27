class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int i=0,j=0;
        
        while(i<s.length()&&j<t.length()){
            while(j<t.length()&&s[i]!=t[j])
                j++;
            if(s[i]==t[j]){
                 i++;
            j++;
            }
           
        }
        
        return i==s.length()?true:false;
        
    }
};