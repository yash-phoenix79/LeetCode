class Solution {
public:
    int maxConsecutive(int b, int t, vector<int>& s) {
        sort(begin(s),end(s));
        int res=0;
        res=max(res,s[0]-b);
        res=max(res,t-s[s.size()-1]);
        
        for(int i=1;i<s.size();i++)
            res=max(res,s[i]-s[i-1]-1);
        
        return res;
        
    }
};