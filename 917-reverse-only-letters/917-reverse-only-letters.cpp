class Solution {
public:
    string reverseOnlyLetters(string s) {
        
        string t="";
        
        for(auto x:s){
            if(isalpha(x))
                t+=x;
        }
        
        int n=t.length()-1;
        
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i]))
                s[i]=t[n--];
        }
        return s;
    }
};