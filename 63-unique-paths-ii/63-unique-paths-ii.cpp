class Solution {
public:
    
    int find(int i,int j,vector<vector<int>>& obs,vector<vector<int>>&dp){
        int n=obs.size();
        int m=obs[0].size();
        
         if(i>=n||j>=m)
            return 0;
        
        if(obs[i][j])
            return dp[i][j]=0;
       
        
                if(i==n-1&&j==m-1)
            return 1;
        
        if(dp[i][j])
            return dp[i][j];

        return dp[i][j]=find(i+1,j,obs,dp)+find(i,j+1,obs,dp);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int n=obs.size();
        int m=obs[0].size();
        
        if(obs[n-1][m-1]||obs[0][0])return 0;
        
        vector<vector<int>>dp(n,vector<int>(m));
        return find(0,0,obs,dp);
        
    }
};