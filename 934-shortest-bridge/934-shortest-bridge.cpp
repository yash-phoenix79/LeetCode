class Solution {
public:
    int d[5]={1,0,-1,0,1};
    
    void paint(int x,int y,vector<vector<int>>& grid,vector<pair<int,int>>&q)
    {
         int n=grid.size();
        if(min(x,y)>=0&&max(x,y)<n&&grid[x][y]==1){
            grid[x][y]=2;
            q.push_back({x,y});
            for(int i=0;i<4;i++)
                paint(x+d[i],y+d[i+1],grid,q);
        }
    }    
    int shortestBridge(vector<vector<int>>& grid) {
     int n=grid.size();
        vector<pair<int,int>>q;
        for(int i=0;i<n&&!q.size();i++){
            for(int j=0;j<n&&!q.size();j++){
                paint(i,j,grid,q);
            }
        }
        
        while(!q.empty())
        {
            vector<pair<int,int>>q1;
            for(auto [a,b]:q){
                for(int i=0;i<4;i++){
                    int X=a+d[i];
                    int Y=b+d[i+1];
                    if(min(X,Y)>=0&&max(X,Y)<n){
                        if(grid[X][Y]==1)
                            return grid[a][b]-2;
                        else if(grid[X][Y]==0){
                            grid[X][Y]=1+grid[a][b];
                            q1.push_back({X,Y});
                        }
                    }
                }
            }
            swap(q,q1);
        }
        return 0;
    }
};