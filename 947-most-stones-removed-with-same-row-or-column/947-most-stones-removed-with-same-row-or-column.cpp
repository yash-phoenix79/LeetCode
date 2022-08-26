class Solution {
public:
    vector<int>vroot;
    
    int getRoot(int v){
        if(vroot[v]!=v)
            vroot[v]=getRoot(vroot[v]);
        return vroot[v];
    }
    
    void connect(int a,int b){
          vroot[getRoot(a)]=vroot[getRoot(b)];
    }
      
    
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vroot=vector<int>(n);
        for(int i=0;i<n;i++)
            vroot[i]=i;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])
                    connect(i,j);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
            if(vroot[i]==i)cnt++;
        return n-cnt;
    }
};