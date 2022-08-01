class Solution {
public:
    
    void find(int v,vector<int>path,vector<vector<int>>& graph, vector<vector<int>>&ans){
        path.push_back(v);
        int n=graph.size();
        
        if(v==n-1)
        {
         ans.push_back(path);
            return;
        }
      
        for(auto x:graph[v]){
            find(x,path,graph,ans);
        }
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<int>path;
        vector<vector<int>>ans;
        
        find(0,path,graph,ans);
        return ans;
    }
};