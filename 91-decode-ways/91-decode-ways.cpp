class Solution {
public:
    
    int find(int idx,string s,vector<int>&dp,int n){
        if(idx==n)
            return 1;
        if(dp[idx]!=-1)
            return dp[idx];
        if(s[idx]=='0')
            return dp[idx]=0;
        if(idx<n-1&&(s[idx]=='1'||(s[idx]=='2'&&(s[idx+1]>='0'&&s[idx+1]<='6'))))
            return dp[idx]=find(idx+1,s,dp,n)+find(idx+2,s,dp,n);
        return dp[idx]=find(idx+1,s,dp,n);
    }
    
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        return find(0,s,dp,n);
    }
};