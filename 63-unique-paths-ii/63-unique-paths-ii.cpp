class Solution {
public:
    
    int find(int x,int y,vector<vector<int>>&dp,vector<vector<int>>& obs){
        int n=obs.size();
        int m=obs[0].size();
        
        if(x>=n||y>=m)
            return 0;
        if(obs[x][y])
            return dp[x][y]=0;
        
        if(x==n-1&&y==m-1)
            return 1;
        if(dp[x][y]!=-1)
            return dp[x][y];
        
        return dp[x][y]=find(x+1,y,dp,obs)+find(x,y+1,dp,obs);
        
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
     int n=obs.size();
        int m=obs[0].size();
        
        if(obs[0][0]||obs[n-1][m-1])return 0;
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return find(0,0,dp,obs);
        
    }
};