class Solution {
public:
    int numberOfSubstrings(string s) {
        int res=0,i=0,j,n=s.length();
        vector<int>cnt(3,0);
        for(j=0;j<n;j++){
            ++cnt[s[j]-'a'];
            while(cnt[0]&&cnt[1]&&cnt[2])
                --cnt[s[i++]-'a'];
            res+=i;
        }
        return res;
    }
};