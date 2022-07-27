class Solution {
public:
    
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    
void isLand(int x,int y,vector<vector<char>>& grid)
{
     int n=grid.size();
        int m=grid[0].size();
    grid[x][y]='0';
    
    for(int i=0;i<4;i++){
        int X=x+dx[i];
        int Y=y+dy[i];
        
        if(X<0||X>=n||Y<0||Y>=m||grid[X][Y]=='0')
            continue;
        isLand(X,Y,grid);
        
    }
    
}
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    res++;
                    isLand(i,j,grid);
                }
            }
        }
        return res;
    }
};