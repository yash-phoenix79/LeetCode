class Solution {
public:
    char findTheDifference(string s, string t) {
      int ans=0;
        for(auto x:t)
            ans+=x;
        for(auto x:s)
            ans-=x;
        return (char)ans;
    }
};