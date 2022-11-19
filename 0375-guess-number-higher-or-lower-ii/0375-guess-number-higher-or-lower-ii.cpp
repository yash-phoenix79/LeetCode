class Solution {
public:
    
    vector<vector<int>>dp;
    
    int find(int l,int r){
        
        if(l>=r)return 0;
        if(dp[l][r]!=INT_MAX)return dp[l][r];
        
        for(int i=l;i<=r;i++)
            dp[l][r]=min(dp[l][r],i+max(find(l,i-1),find(i+1,r)));
        return dp[l][r];
    }
    
    int getMoneyAmount(int n) {
        dp=vector<vector<int>>(n+1,vector<int>(n+1,INT_MAX));
        
        return find(1,n);
        
    }
};