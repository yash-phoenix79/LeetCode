class Solution {
public:
    
    int find(int x,int y,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        int n=grid1.size();
       int m=grid1[0].size();
        
        if(x<0||y<0||x>=n||y>=m||!grid2[x][y])
            return 1;
        grid2[x][y]=0;
        int res=1;
        res&=find(x+1,y,grid1,grid2);
        res&=find(x-1,y,grid1,grid2);
        res&=find(x,y+1,grid1,grid2);
        res&=find(x,y-1,grid1,grid2);
        return res&grid1[x][y];
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        int res=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j])
                    res+=find(i,j,grid1,grid2);
            }
        }
        return res;
    }
};