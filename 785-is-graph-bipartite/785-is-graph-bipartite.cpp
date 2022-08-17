class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int>vis(n,-1);
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    auto cur=q.front();
                    q.pop();
                    for(auto x:graph[cur]){
                        if(vis[x]==-1){
                            q.push(x);
                            vis[x]=vis[cur]^1;
                        }
                        else if(vis[x]==vis[cur])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};