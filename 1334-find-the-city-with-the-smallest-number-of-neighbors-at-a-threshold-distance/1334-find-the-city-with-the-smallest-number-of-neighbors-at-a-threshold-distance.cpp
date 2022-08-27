class Solution {
public:
    
   vector<vector<pair<int,int>>>adj; 
    vector<pair<int,int>>res;
    
    void dijkstra(int v,int n,int thres){
        vector<int>dis(n,INT_MAX);
        dis[v]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({v,0});
        
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            int ver=cur.first;
            int w=cur.second;
            for(auto x:adj[ver]){
                if(dis[x.first]>x.second+w){
                    dis[x.first]=w+x.second;
                    pq.push({x.first,dis[x.first]});
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i!=v&&dis[i]<=thres)
                cnt++;
        }
        
        res.push_back({v,cnt});
        
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        adj=vector<vector<pair<int,int>>>(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        for(int i=0;i<n;i++)
            dijkstra(i,n,distanceThreshold);
        
        sort(res.begin(),res.end(),[](auto &a,auto &b){
           if(a.second==b.second)
               return a.first>b.first;
            return a.second<b.second;
        });
        return res[0].first;
    }
};