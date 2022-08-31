class Solution {
public:
    
    vector<int>vis;
    vector<double>prob;
    bool find=false;
    
    void findProb(int v,vector<vector<int>>&adj,int t,int tar){
        if(t<0)
            return;
        if(find)
            return;
        

           
        
        double cnt=0.0;
        for(auto x:adj[v]){
            if(!vis[x]){
                cnt++;
            }
        }
        
        if(tar==v&&(t==0||(t>0&&cnt==0.0))){
            find=true;
            return;
        }
        
        for(auto x:adj[v]){
            if(!vis[x]){
                vis[x]=1;
                prob[x]=prob[v]*(double)(1/cnt);
                findProb(x,adj,t-1,tar);
            }
        }
        
    }
    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int tar) {
        vector<vector<int>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vis=vector<int>(n+1,0);
        prob=vector<double>(n+1,1);
        
        vis[1]=1;
        
        findProb(1,adj,t,tar);
        if(find)
        return prob[tar];
        return 0.00000;
    }
};