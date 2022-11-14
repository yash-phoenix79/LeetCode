class Solution {
public:
    
    vector<int>mem;
    
    int getParent(int i){
        if(i!=mem[i])
            mem[i]=getParent(mem[i]);
        return mem[i];
    }
    
    void connect(int i,int j){
         mem[getParent(i)]=mem[getParent(j)];
    }
       
    
    int removeStones(vector<vector<int>>& stones) {
        
        int n=stones.size();
        mem=vector<int>(n);
        
        for(int i=0;i<n;i++)
            mem[i]=i;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])
                    connect(i,j);
            }
        }
        
        int cnt=0;
        
        for(int i=0;i<n;i++)
            if(mem[i]==i)cnt++;
        return n-cnt;
        
    }
};