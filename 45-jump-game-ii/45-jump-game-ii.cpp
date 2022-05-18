class Solution {
public:
    
    int find(vector<int>&nums,vector<int>&dp,int pos){
        if(pos>=size(nums)-1)return 0;
        if(dp[pos]!=10001)return dp[pos];
        
        for(int i=1;i<=nums[pos];i++)
        dp[pos]=min(dp[pos],1+find(nums,dp,pos+i));
        
        return dp[pos];
        
    }
    
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),10001);
        return find(nums,dp,0);
    }
};