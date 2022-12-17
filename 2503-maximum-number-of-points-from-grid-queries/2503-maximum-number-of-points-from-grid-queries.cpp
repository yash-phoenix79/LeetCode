class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& g, vector<int>& qu) {
        
        int n=g.size(),m=g[0].size();
        int sz=qu.size();
        
        vector<int>res(sz);
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0]=1;
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        
        vector<pair<int,int>>q(sz);
        for(int i=0;i<sz;i++){
            q[i]={qu[i],i};
        }
        
        sort(begin(q),end(q));
        
        pq.push({g[0][0],0,0});
        int sum=0;
        
        for(auto [cur,idx]:q){
            
            while(pq.size()){
                
                auto [val,x,y]=pq.top();
                if(val>=cur)break;
                else{
                    pq.pop();
                    sum++;
                    if(x-1>=0&&!vis[x-1][y])vis[x-1][y]=1,pq.push({g[x-1][y],x-1,y});
                    if(y-1>=0&&!vis[x][y-1])vis[x][y-1]=1,pq.push({g[x][y-1],x,y-1});
                    if(x+1<n&&!vis[x+1][y])vis[x+1][y]=1,pq.push({g[x+1][y],x+1,y});
                    if(y+1<m&&!vis[x][y+1])vis[x][y+1]=1,pq.push({g[x][y+1],x,y+1});
                }
                
            }
            
            res[idx]=sum;
            
        }
        
        return res;
        
    }
};