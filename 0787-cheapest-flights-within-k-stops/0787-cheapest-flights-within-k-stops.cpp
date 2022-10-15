class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int s, int d, int k) {
     
        
        vector<pair<int,int>>adj[n];
        for(auto x:f)
            adj[x[0]].push_back({x[1],x[2]});
        
        vector<int>dis(n,INT_MAX);
        dis[s]=0;
        
        queue<vector<int>>q;
        q.push({0,s,0});
       
        
        while(!q.empty()){
            
            
                auto cur=q.front();
                q.pop();
                int stop=cur[0];
                int node=cur[1];
                int dist=cur[2];
                
                if(stop>k)
                    continue;
                
                for(auto x:adj[node]){
                    if(dis[x.first]>dist+x.second){
                        dis[x.first]=dist+x.second;
                        q.push({stop+1,x.first,dis[x.first]});
                    }
                }
                
            
            
        }
        
        if(dis[d]==INT_MAX)
            return -1;
        return dis[d];
        
    }
};