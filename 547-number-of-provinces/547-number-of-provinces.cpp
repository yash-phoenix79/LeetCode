class Solution {
public:
    
    void connect(int v,vector<vector<int>>& isConnected,vector<int>&visit){
        int n=isConnected.size();
        visit[v]=1;
        for(int i=0;i<n;i++){
            if(i!=v&&isConnected[v][i]&&!visit[i])
                connect(i,isConnected,visit);
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        vector<int>visit(n,0);
        
        int res=0;
        
        for(int i=0;i<n;i++){
            if(!visit[i])
            {
                res++;
                connect(i,isConnected,visit);
            }
        }
        return res;
    }
};