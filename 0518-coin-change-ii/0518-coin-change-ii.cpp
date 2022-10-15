class Solution {
public:
    
    vector<vector<int>>dp;
    
    int find(int idx,int amt,vector<int>&coins)
    {
        int n=coins.size();
        if(idx>=n)
            return 0;
        
        if(amt==0)
            return 1;
        
        if(dp[amt][idx]!=-1)
            return dp[amt][idx];
        
        int res=0;
        for(int i=idx;i<n;i++){
            if(coins[i]<=amt)
                res+=find(i,amt-coins[i],coins);
        }
        
        return dp[amt][idx]=res;
        
    }
    
    
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        dp=vector<vector<int>>(amount+1,vector<int>(n+1,-1));
        // sort(coins.begin(),coins.end());
        return find(0,amount,coins);
        
    }
};