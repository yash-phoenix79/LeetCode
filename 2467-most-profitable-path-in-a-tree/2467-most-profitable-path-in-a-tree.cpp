class Solution {
public:
    
    bool dfs(int v,int t,vector<vector<int>>&adj,vector<int>&vis,unordered_map<int,int>&m){
        
        vis[v]=1;
        m[v]=t;
        
        if(v==0)
            return true;
        
        for(auto x:adj[v]){
            if(!vis[x])
                if(dfs(x,t+1,adj,vis,m))
                    return true;
        }
        
        m.erase(v);
        return false;
        
    }
    
    int mostProfitablePath(vector<vector<int>>& e, int b, vector<int>& a) {
        
        int n=a.size();
        vector<vector<int>>adj(n);
        for(auto x:e){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int>vis(n,0);
        unordered_map<int,int>m;
        
        dfs(b,0,adj,vis,m);
        
        queue<vector<int>>q;
        q.push({0,0,0});
        
        vis.assign(n,0);
        
        int res=INT_MIN;
        
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            int v=cur[0],am=cur[1],t=cur[2];
            vis[v]=1;
            
            if(m.find(v)==m.end())
                am+=a[v];
            else{
                if(m[v]>t)
                    am+=a[v];
                else if(m[v]==t)
                    am+=(a[v]/2);
            }
            
            if(adj[v].size()==1&&v!=0)
            res=max(res,am);
            
            for(auto x:adj[v]){
                if(!vis[x])
                    q.push({x,am,t+1});
            }
            
        }
        return res;
        
    }
};