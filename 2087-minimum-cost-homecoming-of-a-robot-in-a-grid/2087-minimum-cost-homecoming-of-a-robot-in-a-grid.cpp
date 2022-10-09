class Solution {
public:
    int minCost(vector<int>& s, vector<int>& h, vector<int>& r, vector<int>& c) {
        
        int dr=s[0]<h[0]?-1:1;
        int dc=s[1]<h[1]?-1:1;
        int res=0;
        
        for(int x=h[0];x!=s[0];x+=dr)
            res+=r[x];
        for(int y=h[1];y!=s[1];y+=dc)
            res+=c[y];
        return res;
        
    }
};