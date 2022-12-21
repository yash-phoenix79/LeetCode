class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        
        vector<int>vis(n+1,0);
        
        vector<vector<int>>adj(n+1);
        
        for(auto x:d){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        queue<int>q;
        
        for(int i=1;i<=n;i++){
            
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
                
                while(!q.empty()){
                    
                    int sz=q.size();
                    while(sz--){
                        
                        int cur=q.front();
                        q.pop();
                        
                        for(auto x:adj[cur]){
                            if(!vis[x]){
                                vis[x]=-1*vis[cur];
                                q.push(x);
                            }
                            else if(vis[x]==vis[cur])
                                return false;
                        }
                        
                    }
                    
                }
                
            }
            
        }
            
        return true;
        
    }
};