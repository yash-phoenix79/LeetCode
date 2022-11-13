class Solution {
public:
    
    bool dfs(int v,vector<vector<int>>&adj,vector<int>&vis,unordered_map<int,int>&path,int time){
        
        path[v]=time;
        vis[v]=1;
        
        if(v==0)
            return true;
        
        for(auto x:adj[v]){
            if(!vis[x])
                if(dfs(x,adj,vis,path,time+1))
                    return true;
        }
        
        path.erase(v);
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
        
        dfs(b,adj,vis,m,0);
        
        int ans=INT_MIN;
        
        queue<vector<int>>q;
        q.push({0,0,0});
        
        vis.assign(n,0);
        
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
                ans=max(ans,am);
            
            for(auto x:adj[v]){
                if(!vis[x])
                    q.push({x,am,t+1});
                    
            }
            
        }
        return ans;
    }
};