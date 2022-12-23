class Solution {
public:
    
    vector<vector<int>>adj;
    vector<int>res,cnt;
    
    
    void dfs(int i,int p=-1){
        
        for(auto x:adj[i]){
            if(x==p)continue;
            dfs(x,i);
            cnt[i]+=cnt[x];
            res[i]+=res[x]+cnt[x];
        }
        cnt[i]++;
    }
    
    void dfs2(int i,int n,int p=-1){
        
        for(auto x:adj[i]){
            if(x==p)continue;
            res[x]=res[i]-cnt[x]+n-cnt[x];
            dfs2(x,n,i);    
        }
        
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& e) {
        
        adj.resize(n);
        res.resize(n);
        cnt.resize(n);
        
        for(auto x:e){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        dfs(0);
        dfs2(0,n);
        
        return res;
        
    }
};