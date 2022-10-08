class Solution {
public:
    
    vector<int>dp;
    
    int find(vector<int>&nums,int n,int t){
        
        if(t==0)
            return 1;
        
        if(dp[t]!=-1)
            return dp[t];
        int res=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=t)
                res+=find(nums,n,t-nums[i]);
        }
        return dp[t]=res;
    }
    
    int combinationSum4(vector<int>& nums, int t) {
        
        dp.resize(t+1,-1);
        dp[0]=0;
        int n=nums.size();
        return find(nums,n,t);
        
    }
};