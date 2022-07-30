class Solution {
public:
    int d[5]={0,1,0,-1,0};
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int res=-1;
        
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j])
                q.push({i,j});
            }
        }
        int t=1;
        while(!q.empty()){
            int sz=q.size();
          
            
            for(int i=0;i<sz;i++){
                auto cur=q.front();
                q.pop();
                // cout<<cur.first<<" "<<cur.second<<endl;
                int x=cur.first;
                int y=cur.second;
                
                for(int i=0;i<4;i++){
                    int dx=x+d[i];
                    int dy=y+d[i+1];
                    if(dx<0||dy<0||dx>=n||dy>=m||grid[dx][dy]!=0)
                        continue;
                    else{
                        grid[dx][dy]=t;
                       res=max(res,t);
                    q.push({dx,dy}); 
                    }
                    
                }
            }
            // cout<<endl;
            t++;
        }
        return res;
    }
};