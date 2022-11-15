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
    
    
    long long countPairs(int n, vector<vector<int>>& e) {
        
        long long res=0;
        par=vector<int>(n);
        
        for(int i=0;i<n;i++)
            par[i]=i;
        
        for(int i=0;i<e.size();i++)
        {
            connect(e[i][0],e[i][1]);
        }
        
 
        int sum=0;
        
        unordered_map<int,int>m;
      
        for(auto p:par){
            m[getPar(p)]++;
        }
        
       
        for(auto [a,b]:m){
            res+=(long long)(b)*(n-b);
            n-=b;
        }
        
        return res;
        
    }
};