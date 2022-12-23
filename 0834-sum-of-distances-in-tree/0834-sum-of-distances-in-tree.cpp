class Solution {
public:
    
    vector<vector<int>>adj;
    vector<int>cnt,res;
    
    
    void dfs(int v,int p=-1){
        
        for(auto x:adj[v]){
            if(x==p)continue;
            dfs(x,v);
            cnt[v]+=cnt[x];
            res[v]+=res[x]+cnt[x];
        }
        cnt[v]++;
    }
    
    void dfs2(int v,int n,int p=-1){
        
        for(auto x:adj[v]){
            if(x==p)continue;
            res[x]=res[v]-cnt[x]+n-cnt[x];
            dfs2(x,n,v);
        }
        
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& e) {
        
        adj.resize(n);
        
        for(auto x:e){
            
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            
        }
        
        cnt.resize(n);
        res.resize(n);
        
        dfs(0);
        dfs2(0,n);
        
        return res;
    }
};