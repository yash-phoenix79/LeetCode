class Solution {
public:
    string reverseWords(string s) {
        string t1;
        stringstream t(s);
        
        getline(t,s,' ');
        reverse(s.begin(),s.end());
        string res=s;
        
        while(getline(t,s,' ')){
            res+=' ';
            reverse(s.begin(),s.end());
            res+=s;
        }
        return res;
    }
};