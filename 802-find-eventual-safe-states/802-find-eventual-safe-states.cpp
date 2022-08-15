class Solution {
public:
    bool check(int v,vector<vector<int>>& graph,vector<int>&col){
        col[v]=1;
        for(auto x:graph[v])
        {
            if(!col[x]&&check(x,graph,col)||col[x]==1)
                return true;
        }
        col[v]=2;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
       vector<int>col(n,0);
        vector<int>res;
        
        for(int i=0;i<n;i++){
            if(col[i]==2||!check(i,graph,col))
                res.push_back(i);
        }
        return res;
    }
};