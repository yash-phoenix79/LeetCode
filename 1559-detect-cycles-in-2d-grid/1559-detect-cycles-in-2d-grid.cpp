class Solution {
public:
    
    int d[5]={1,0,-1,0,1};
    
    
    bool dfs(int x,int y,vector<vector<char>>& grid,vector<vector<int>>&vis,int pX,int pY){
        
        int n=grid.size();
        int m=grid[0].size();
        
       vis[x][y]=1;
        
        for(int i=0;i<4;i++){
            int dx=x+d[i];
            int dy=y+d[i+1];
            
            
            
            if(dx>=0&&dy>=0&&dx<n&&dy<m&&grid[x][y]==grid[dx][dy]&&(!(dx==pX&&dy==pY))){
               if(vis[dx][dy]||dfs(dx,dy,grid,vis,x,y))
                return true;
            }
    
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
    
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&dfs(i,j,grid,vis,-1,-1)){
                    return true;
                }   
            }
        }
        
        return false;
        
    }
};