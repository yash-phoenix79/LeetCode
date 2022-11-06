class Solution {
public:
    
    bool check(int x,int y,vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        
        if(x<0||y<0||x>=n||y>=m)return false;
        return true;
        
    }
    
    void dfs(int x,int y,vector<vector<int>>&vis,vector<vector<int>>&grid){
        
        int n=grid.size();
        int m=grid[0].size();
        
        if(vis[x][y])return;
        
        vis[x][y]=1;
        
        int u,d,l,r;
        u=d=l=r=0;
        
        int X,Y;
        
        if(grid[x][y]==1){
            l=1,r=1;
        }
        else if(grid[x][y]==2){
            u=1,d=1; 
        }
        else if(grid[x][y]==3){
            l=1,d=1;
        }
        else if(grid[x][y]==4){
            r=1,d=1;
        }
        else if(grid[x][y]==5){
            u=1,l=1;
        }
        else {
            u=1,r=1;
        }
        
        if(u){
            X=x-1,Y=y;
            if(check(X,Y,grid)&&(grid[X][Y]==2||grid[X][Y]==3||grid[X][Y]==4))
                dfs(X,Y,vis,grid);
        }
        
        if(d){
            X=x+1,Y=y;
             if(check(X,Y,grid)&&(grid[X][Y]==2||grid[X][Y]==5||grid[X][Y]==6))
                dfs(X,Y,vis,grid);
        }
        
        if(l){
            X=x,Y=y-1;
             if(check(X,Y,grid)&&(grid[X][Y]==1||grid[X][Y]==6||grid[X][Y]==4))
                dfs(X,Y,vis,grid);
        }
        
        if(r){
            X=x,Y=y+1;
             if(check(X,Y,grid)&&(grid[X][Y]==1||grid[X][Y]==3||grid[X][Y]==5))
                dfs(X,Y,vis,grid);
        }
        
        
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        dfs(0,0,vis,grid);
        
        return vis[n-1][m-1];
        
    }
};