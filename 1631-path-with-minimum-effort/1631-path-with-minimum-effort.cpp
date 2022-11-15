class Solution {
public:
    
    #define pii pair<int,pair<int,int>>
    
    int d[5]={1,0,-1,0,1};
    
    int minimumEffortPath(vector<vector<int>>& h) {
        
        int n=h.size();
        int m=h[0].size();
        
        priority_queue<pii,vector<pii>,greater<pii>>q;
        q.push({0,{0,0}});
        
        vector<vector<int>>vis(n,vector<int>(m,INT_MAX));
        vis[0][0]=0;
        
        while(!q.empty()){
            auto cur=q.top();
            q.pop();
            int dis=cur.first;
            int x=cur.second.first;
            int y=cur.second.second;
            
            if(x==n-1&&y==m-1)
                return dis;
            
            for(int i=0;i<4;i++){
                
                int dx=x+d[i];
                int dy=y+d[i+1];
                
                if(dx<0||dy<0||dx>=n||dy>=m)continue;
                int val=max(dis,abs(h[dx][dy]-h[x][y]));
                if(val<vis[dx][dy]){
                    vis[dx][dy]=val;
                    q.push({val,{dx,dy}});
                }
                
            }
            
        }
        
        return 0;
        
    }
};