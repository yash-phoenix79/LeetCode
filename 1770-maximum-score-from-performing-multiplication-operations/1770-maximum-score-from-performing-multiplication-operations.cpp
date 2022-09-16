class Solution {
public:
    vector<vector<int>>dp;
    
    int find(int i,int j,vector<int>& nums, vector<int>& mul){
        
         int n=nums.size();   
        int m=mul.size();
        
        if(j>=mul.size())
            return 0;
        
        if(dp[i][j]!=INT_MIN)
            return dp[i][j];
        
        int t1=find(i+1,j+1,nums,mul)+mul[j]*nums[i];
        int t2=find(i,j+1,nums,mul)+mul[j]*(nums[n-1-(j-i)]);
        
        return dp[i][j]=max(t1,t2);
        
    }
    
    int maximumScore(vector<int>& nums, vector<int>& mul) {
     int n=nums.size();   
        int m=mul.size();
        dp.resize(m+1,vector<int>(m+1,INT_MIN));
        return find(0,0,nums,mul);
        
        
    }
};