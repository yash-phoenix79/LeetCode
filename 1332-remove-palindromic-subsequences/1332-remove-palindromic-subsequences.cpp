class Solution {
public:
    int removePalindromeSub(string s) {
        
        string t=s;
        reverse(s.begin(),s.end());
        if(s==t)
            return 1;
        return 2;
        
    }
};