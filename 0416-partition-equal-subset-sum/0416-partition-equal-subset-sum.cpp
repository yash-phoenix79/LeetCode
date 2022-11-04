class Solution {
public:
    
    int a;
    vector<vector<int>>dp;
    
    bool find(int idx,int sum,vector<int>&nums){
        
        if(sum==a)
            return 1;
        if(sum>a)
            return 0;
         int n=nums.size();
        if(idx>=n)return 0;
        
        if(dp[idx][sum]!=-1)
            return dp[idx][sum];
        
        return dp[idx][sum]=find(idx+1,sum,nums)||find(idx+1,sum+nums[idx],nums);
        
    }
    
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        int s=0;
        for(auto x:nums)
            s+=x;
        
        if(s%2)return false;
        a=s/2;
        
        dp=vector<vector<int>>(n+2,vector<int>(s,-1));
        
        return find(0,0,nums);
        
        
    }
};