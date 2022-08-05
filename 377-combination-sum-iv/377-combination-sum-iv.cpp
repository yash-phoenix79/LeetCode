class Solution {
public:
   
    
    int find(vector<int>&nums,int n,int t,vector<int>&dp){
        if(t==0)
        {
           return 1;
        }
        
        if(dp[t]!=-1)
            return dp[t];
        int res=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=t)
                res+=find(nums,n,t-nums[i],dp);
        }
        return dp[t]=res;
    }
    
    int combinationSum4(vector<int>& nums, int tar) {
        int n=nums.size();
        vector<int>dp(tar+1,-1);
        dp[0]=0;
       return find(nums,n,tar,dp);
        
    }
};