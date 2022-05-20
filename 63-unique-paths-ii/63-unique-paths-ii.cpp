class Solution {
public:
      
    int findPath(int i,int j,vector<vector<int>>& obs,vector<vector<int>>&dp){
        
          int n=obs.size(),m=obs[0].size();
        
         if(i<0||i>=n||j<0||j>=m)
            return 0;
        
        if(obs[i][j])
            return dp[i][j]=0;
      
        if(i==n-1&&j==m-1)return 1;
        
        if(dp[i][j])return dp[i][j];
        
        
    return  dp[i][j]=findPath(i,j+1,obs,dp)+findPath(i+1,j,obs,dp);
       
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int n=obs.size(),m=obs[0].size();
        if(obs[n-1][m-1])return 0;
        vector<vector<int>>dp(n,vector<int>(m));
        
        return findPath(0,0,obs,dp);
        
       
        
    }
};