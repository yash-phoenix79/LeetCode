class Solution {
public:
    int d[5]={1,0,-1,0,1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        
        int n=mat.size();
        int m=mat[0].size();
        
      vector<vector<int>>res(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]){
                    res[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
         
                auto cur=q.front();
                q.pop();
                int x=cur.first;
                int y=cur.second;
                for(int i=0;i<4;i++){
                    int dx=x+d[i];
                    int dy=y+d[i+1];
                    if(dx<0||dy<0||dx>=n||dy>=m)
                     continue;
                   if(res[dx][dy]>1+res[x][y]){
                        res[dx][dy]=1+res[x][y];
                       q.push({dx,dy});
                    }
                     
                }
            
        }
        return res;
    }
};