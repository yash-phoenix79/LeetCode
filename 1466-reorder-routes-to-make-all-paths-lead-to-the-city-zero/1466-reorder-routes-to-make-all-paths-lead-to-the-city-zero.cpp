class Solution {
public:
    
    int res=0;
    
    int minReorder(int n, vector<vector<int>>& con) {

        vector<vector<int>>g(n),nei(n);
        vector<int>vis(n,0);
        
        for(int i=0;i<con.size();i++)
        {
            g[con[i][0]].push_back(con[i][1]);
            nei[con[i][0]].push_back(con[i][1]);
            nei[con[i][1]].push_back(con[i][0]);
        }
        
        queue<int>q;
        q.push(0);
        vis[0]=1;
        
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            
            for(auto x:nei[cur]){
                if(find(begin(g[cur]),end(g[cur]),x)!=end(g[cur])&&!vis[x])
                {
                    res++;
                    vis[x]=1;
                    q.push(x);
                    // cout<<x<<endl;
                }
                else if(!vis[x]){
                    vis[x]=1;
                   q.push(x);  
                     // cout<<x<<endl;
                }

            }
            
        }
        
        return res;
        
        
    }
};