class Solution {
public:
    
    vector<int>par;
    
    int getPar(int x){
        if(x!=par[x])
            par[x]=getPar(par[x]);
        return par[x];
    }
    
    void connect(int a,int b){
        
        par[getPar(a)]=par[getPar(b)];
        
    }
    
    int findCircleNum(vector<vector<int>>& con) {
        
        int n=con.size();
        par=vector<int>(n);
        for(int i=0;i<n;i++)
            par[i]=i;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(con[i][j])
                    connect(i,j);
            }
        }
        
        int res=0;
        
        for(int i=0;i<n;i++){
            if(par[i]==i)
                res++;
        }
        
        return res;
        
    }
};