class Solution {
public:
    char findTheDifference(string s, string t) {
        char c=0;
        for(auto x:s)c^=x;
        for(auto x:t)c^=x;
        return c;
    }
};