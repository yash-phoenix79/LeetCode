class Solution {
public:
    
    int n,m,mod=1e9+7;
    
    int find(int x,int y,int s,vector<vector<vector<int>>>&dp,vector<vector<int>>& grid,int k){
        if(x>=n||y>=m)return 0;
        
        if(x==n-1&&y==m-1){
            if((s+grid[x][y])%k==0)
                return 1;
            return 0;
        }
        
        if(dp[x][y][s]!=-1)
            return dp[x][y][s];
        
        return  dp[x][y][s]=(find(x+1,y,(s+grid[x][y])%k,dp,grid,k)+find(x,y+1,(s+grid[x][y])%k,dp,grid,k))%mod;
        
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return find(0,0,0,dp,grid,k);
        
    }
};