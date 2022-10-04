class Solution {
public:
    
    int find(vector<int>&coins,int amount,vector<int>&dp){
         int n=coins.size();
        if(dp[amount]!=-1)
            return dp[amount];
        int res=INT_MAX/2;
        for(int i=0;i<n;i++){
            if(coins[i]<=amount)
                res=min(res,1+find(coins,amount-coins[i],dp));
        }
        return dp[amount]=res;
    }
    
    int coinChange(vector<int>& coins, int amount) {
     int n=coins.size();
        vector<int>dp(amount+1,-1);
        
      dp[0]=0;
        
      int res=find(coins,amount,dp);
        if(res==INT_MAX/2)
            return -1;
        return res;
    }
};