class Solution {
public:
    
     vector<vector<int>>dp;
    
    int find(int i,int j,vector<int>& nums, vector<int>& mul){
         int n=nums.size();
        int m=mul.size();
        
        if(j>=m)
            return 0;
        
        if(dp[i][j]!=INT_MIN)
            return dp[i][j];
        
        int left=find(i+1,j+1,nums,mul)+mul[j]*nums[i];
        int right=find(i,j+1,nums,mul)+mul[j]*nums[n-1-(j-i)];
        
        return dp[i][j]=max(left,right);
        
    }
    
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n=nums.size();
        int m=mul.size();
        
       dp.resize(m+1,vector<int>(m+1,INT_MIN));
        
        return find(0,0,nums,mul);
        
    }
};