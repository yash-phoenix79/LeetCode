class Solution {
public:
    
    int solve(int idx,vector<int>&nums,vector<vector<int>>&dp,int prev){
         int n=nums.size();
        if(idx==n)return 0;
        if(dp[idx][prev+1]!=-1)
            return dp[idx][prev+1];
        int take=0,notTake=solve(idx+1,nums,dp,prev);
        if(prev==-1||nums[idx]>nums[prev])
            take=1+solve(idx+1,nums,dp,idx);
        return dp[idx][prev+1]=max(take,notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,nums,dp,-1);
    }
};