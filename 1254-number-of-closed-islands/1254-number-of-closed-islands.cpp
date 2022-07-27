class Solution {
public:
    
    bool check(int i,int j,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0||j<0||i>=n||j>=m)
            return false;
        if(grid[i][j])
            return true;
        
        grid[i][j]=1;
        
        bool b1=check(i+1,j,grid);
         bool b2=check(i-1,j,grid);
         bool b3=check(i,j+1,grid);
         bool b4=check(i,j-1,grid);
        
        return b1&&b2&&b3&&b4;
        
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!grid[i][j])
                   res+=check(i,j,grid)?1:0; 
            }
        }
        return res;
    }
};