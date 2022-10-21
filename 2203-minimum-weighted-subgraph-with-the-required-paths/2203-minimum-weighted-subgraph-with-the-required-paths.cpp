class Solution {
public:
    
    typedef pair<long,long> p;
    
    
    vector<long>dijkstra(vector<vector<p>>adj,int s){
        
        int n=adj.size();
        
        vector<long>dis(n,LONG_MAX);
        priority_queue<p,vector<p>,greater<p>>q;
        q.push({s,0});
        dis[s]=0;
        
        while(!q.empty()){
            
           auto [u,cost]=q.top();
            q.pop();
            
            if(cost>dis[u])continue;
            for(auto &[v,c]:adj[u]){
                if(dis[v]>dis[u]+c){
                    dis[v]=dis[u]+c;
                    q.push({v,dis[v]});
                }
            }
            
        }
        return dis;
        
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        
        vector<vector<p>>adj(n),rev(n);
        
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
            rev[x[1]].push_back({x[0],x[2]});
        }
        
        vector<long>ds1,ds2,dd;
        
        ds1=dijkstra(adj,src1);
        ds2=dijkstra(adj,src2);
        dd=dijkstra(rev,dest);
        
        long  res=LONG_MAX;
        
        for(int i=0;i<n;i++){
            
            if(ds1[i]==LONG_MAX||ds2[i]==LONG_MAX||dd[i]==LONG_MAX)continue;
            res=min(res,ds1[i]+ds2[i]+dd[i]);
        }
        
        return res==LONG_MAX?-1:res;
        
    }
};