class Solution {
public:
    
    vector<int>par;
    
    int getPar(int i){
        if(i!=par[i])
            par[i]=getPar(par[i]);
        return par[i];
    }
    
    void connect(int a,int b){
        par[getPar(a)]=par[getPar(b)];
    }
    
    int minCostConnectPoints(vector<vector<int>>& p) {
        
        int n=p.size();
        
        vector<pair<int,pair<int,int>>>adj;
        
        par=vector<int>(n);
        for(int i=0;i<n;i++)
            par[i]=i;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dis=abs(p[i][0]-p[j][0])+abs(p[i][1]-p[j][1]);
                adj.push_back({dis,{i,j}});
            }
        }
        
        sort(begin(adj),end(adj));
        
        int res=0;
        
        for(int i=0;i<adj.size();i++){
            
            auto cur=adj[i];
            int a=cur.second.first;
            int b=cur.second.second;
            
            if(getPar(a)!=getPar(b))
            {
                connect(a,b);
                res+=cur.first;
            }
        }
        
        return res;
        
    }
};