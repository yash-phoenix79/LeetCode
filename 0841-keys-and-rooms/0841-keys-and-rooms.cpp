class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& r) {
        
        int n=r.size();
        vector<int>vis(n,0);
        
        queue<int>q;
        q.push(0);
        vis[0]=1;
        
        while(!q.empty()){
            
            int sz=q.size();
            while(sz--){
                int cur=q.front();
                q.pop();
                for(auto x:r[cur]){
                    if(vis[x])continue;
                    else{
                        vis[x]=1;
                        q.push(x);
                    }
                }
            }
            
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i])return false;
        }
        
        return true;
        
    }
};