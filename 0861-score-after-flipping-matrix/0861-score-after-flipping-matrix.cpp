class Solution {
public:
    
    void flip(int c,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++)
            grid[i][c]^=1;
        
    }
    
    int matrixScore(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int>cnt(m,0);
        
        for(int i=0;i<n;i++){
            bool flag=false;
            if(!grid[i][0])
                flag=true;
            for(int j=0;j<m;j++){
                
                if(flag){
                    grid[i][j]^=1;
                }
                if(grid[i][j])
                    cnt[j]++;
            }
        }
        
        for(int i=1;i<m;i++){
            if(!(cnt[i]>n/2))
                flip(i,grid);
            // cout<<cnt[i]<<" ";
            
        }
        // cout<<endl;
        int res=0;
        
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++)
//             {
//                 cout<<grid[i][j]<<' ';
//             }
//             cout<<endl;
//         }
        
        for(int i=0;i<n;i++){
            int t=0,x=0;
            for(int j=0;j<m;j++){
                x=grid[i][j]<<(m-j-1);
                t+=x;
            }
            res+=t;
        }
        return res;
    }
};