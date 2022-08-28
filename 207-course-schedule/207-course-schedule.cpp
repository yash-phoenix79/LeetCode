class Solution {
public:
    
    bool check(int v,vector<vector<int>>&adj,vector<int>&vis,vector<int>&rec){
        vis[v]=1;
        rec[v]=1;
        
        for(auto x:adj[v]){
            if(!vis[x]&&!check(x,adj,vis,rec))
                return false;
            if(rec[x])
                return false;
        }
        rec[v]=0;
        return true;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>>adj(n);
        for(int i=0;i<pre.size();i++)
            adj[pre[i][0]].push_back(pre[i][1]);
        
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])
            {
                vector<int>recStack(n,0);
                if(!check(i,adj,vis,recStack))
                    return false;
            }
        }
        
        return true;
        
    }
};