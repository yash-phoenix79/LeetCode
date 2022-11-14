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
    
    bool validPath(int n, vector<vector<int>>& e, int source, int destination) {
     
        par=vector<int>(n);
        for(int i=0;i<n;i++)
            par[i]=i;
        
        for(int i=0;i<e.size();i++){
            connect(e[i][0],e[i][1]);
        }
        
        return getPar(source)==getPar(destination);
        
    }
};