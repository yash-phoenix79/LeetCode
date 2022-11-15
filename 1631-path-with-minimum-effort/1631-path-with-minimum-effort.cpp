class Solution {
public:
    
    int d[5]={1,0,-1,0,1};
    
    int minimumEffortPath(vector<vector<int>>& h) {
       
        int n=h.size(),m=h[0].size();
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
        vector<vector<int>>vis(n,vector<int>(m,INT_MAX));
        
        vis[0][0]=0;
        
        pq.push({0,0,0});
        
        while(!pq.empty()){
            
            auto cur=pq.top();
            pq.pop();
            
            int dis=cur[0],x=cur[1],y=cur[2];
            
            if(x==n-1&&y==m-1)return dis;
            
            for(int i=0;i<4;i++){
                int dx=x+d[i];
                int dy=y+d[i+1];
                
                if(dx<0||dy<0||dx>=n||dy>=m)continue;
                
                int nd=max(dis,abs(h[dx][dy]-h[x][y]));
                
                if(nd<vis[dx][dy]){
                    vis[dx][dy]=nd;
                    pq.push({nd,dx,dy});
                }
                
                
            }
            
        }
    
        return 0;
    }
};