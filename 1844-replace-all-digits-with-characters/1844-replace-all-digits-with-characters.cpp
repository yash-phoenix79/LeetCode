class Solution {
public:
    string replaceDigits(string s) {
        
        for(int i=1;i<s.length();i++){
            if(i%2){
                int t=s[i]-'0';
                s[i]=s[i-1]+t;
            }
        }
        return s;
    }
};