class Solution {
public:
    int res=0; 
    
    void find(int v,vector<vector<int>>&adj,vector<int>& in,int t){
        res=max(res,t);
        for(auto x:adj[v]){
            find(x,adj,in,t+in[v]);
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& in) {
        
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
                 adj[manager[i]].push_back(i);
        }
           
        find(headID,adj,in,0);
        return res;
        
    }
};