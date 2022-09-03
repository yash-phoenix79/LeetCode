class Solution {
public:
    
    int d[5]={1,0,-1,0,1};
    
    void dfs(int x,int y,vector<vector<int>>& grid,vector<vector<int>>&vis){
         int n=grid.size();
        int m=grid[0].size();
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int dx=x+d[i];
            int dy=y+d[i+1];
            if(dx>=0&&dx<n&&dy>=0&&dy<m&&grid[dx][dy]==1&&vis[dx][dy]==-1)
                dfs(dx,dy,grid,vis);
        }
    }
    
    int countIslands(vector<vector<int>>& grid){
           int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,-1));
        
        int islands=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==-1&&grid[i][j]){
                    dfs(i,j,grid,vis);
                    islands++;
                }
            }
        }
        return islands;
    }
    
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int islands=countIslands(grid);
        
        if(islands>1||islands==0)return 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                    islands=countIslands(grid);
                    grid[i][j]=1;
                    if(islands>1||islands==0)return 1;
                }
            }
        }
        return 2;
    }
};