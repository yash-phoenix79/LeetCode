class Solution {
public:
    
    int l;
    
    vector<int> find(int v,vector<vector<int>>&adj){
        int n=adj.size();
        vector<int>vis(n,-1);
        vis[v]=0;
        
        queue<int>q;
        q.push(v);
        
        int t=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int x=q.front();
                q.pop();
                l=x;
                for(auto a:adj[x]){
                    if(vis[a]==-1){
                        vis[a]=t;
                        q.push(a);
                    }
                }
            }
            t++;
        }
        
//         cout<<l<<" ";
        
        return vis;
        
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) {
       
        
        vector<vector<int>>adj(n);
        for(auto x:e){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
     
        queue<int>q;
        q.push(0);
        vector<int>vis(n,0);
        vis[0]=1;
        
        while(!q.empty()){
            int v=q.front();
            q.pop();
            l=v;
            for(auto x:adj[v]){
                if(!vis[x]){
                    vis[x]=1;
                    q.push(x);
                }
            }
        }
        
        // cout<<l<<endl;
        
        vector<int>f=find(l,adj);
        vector<int>s=find(l,adj);
        
        vector<int>res(n);
        
        for(int i=0;i<n;i++)
            res[i]=max(f[i],s[i]);
        
        int te=INT_MAX;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(res[i]<te){
                te=res[i];
                ans.clear();
                ans.push_back(i);
            }
            else if(res[i]==te)
                ans.push_back(i);
            
            // cout<<res[i]<<" ";
            
        }
        
        return ans;
        
    }
};