class Solution {
public:
    
    vector<int>par;
    
    int getPar(int i){
        
        if(par[i]!=i)
            par[i]=getPar(par[i]);
        return par[i];
    }
    
    void connect(int a,int b){
        par[getPar(a)]=par[getPar(b)];
    }
    
    int minCostConnectPoints(vector<vector<int>>& p) {
        
        int n=p.size();
        
        par=vector<int>(n);
        for(int i=0;i<n;i++)
            par[i]=i;
        
        vector<pair<int,pair<int,int>>>adj;
        
     
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dis=abs(p[i][0]-p[j][0])+abs(p[i][1]-p[j][1]);
                
                adj.push_back({dis,{i,j}});
            }
        }
        
         sort(begin(adj),end(adj));
        
        int res=0;
        
        for(int i=0;i<adj.size();i++){
            
            auto t=adj[i];
            int a=t.second.first;
            int b=t.second.second;
            
            if(getPar(a)!=getPar(b)){
                res+=t.first;
                connect(a,b);
   
            }
            // if(cnt==n)
            //     break;
        }
        
        return res;
        
    }
};