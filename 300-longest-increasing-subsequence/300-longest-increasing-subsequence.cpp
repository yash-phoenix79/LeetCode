class Solution {
public:
    
    int solve(int i,vector<int>&nums,vector<int>&dp,int prev){
        int n=nums.size();
        if(i==n)
            return 0;
        if(dp[prev+1]!=-1)
            return dp[prev+1];
        int take=0,notTake=solve(i+1,nums,dp,prev);
        if(prev==-1||nums[i]>nums[prev])
            take=1+solve(i+1,nums,dp,i);
        return dp[prev+1]=max(take,notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,nums,dp,-1);
    }
};