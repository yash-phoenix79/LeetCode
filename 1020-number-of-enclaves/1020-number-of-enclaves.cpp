class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(x<0||y<0||x>=n||y>=m||!grid[x][y])
            return;
        grid[x][y]=0;
        dfs(x+1,y,grid);
        dfs(x-1,y,grid);
        dfs(x,y+1,grid);
        dfs(x,y-1,grid);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int res=0;
        
        for(int i=0;i<n;i++){
            if(grid[i][0])
                dfs(i,0,grid);
            if(grid[i][m-1])
                dfs(i,m-1,grid);
        }
        
        for(int i=0;i<m;i++){
            if(grid[0][i])
                dfs(0,i,grid);
            if(grid[n-1][i])
                 dfs(n-1,i,grid);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j])
                    res++;
            }
        }
        return res;
    }
};