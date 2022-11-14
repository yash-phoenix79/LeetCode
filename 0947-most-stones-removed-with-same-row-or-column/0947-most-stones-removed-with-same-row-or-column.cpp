class Solution {
public:
    
    vector<int>par;
    
    int getPar(int i){
        if(par[i]!=i)
            par[i]=getPar(par[i]);
        return par[i];
    }
    
    void connect(int i,int j){
         par[getPar(i)]=par[getPar(j)];
    }
       
    
    int removeStones(vector<vector<int>>& stones) {
        
        int n=stones.size();
        par=vector<int>(n);
        
        for(int i=0;i<n;i++)
            par[i]=i;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])
                    connect(i,j);
            }
        }
        
        int cnt=0;
        
        for(int i=0;i<n;i++)
            if(par[i]==i)cnt++;
        return n-cnt;
        
    }
};