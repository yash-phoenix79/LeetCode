class Solution {
public:
    int ans=0;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    
    int area(int x,int y,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        int res=1;
        grid[x][y]=0;
        for(int i=0;i<4;i++){
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            if(new_x<0||new_y<0||new_x>=n||new_y>=m||!grid[new_x][new_y])
                continue;
            
                res+=area(new_x,new_y,grid);
        }
        return res;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j])
                    ans=max(ans,area(i,j,grid));
            }
        }
        return ans;
    }
};