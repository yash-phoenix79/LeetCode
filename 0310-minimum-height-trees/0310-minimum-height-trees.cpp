class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) {
        
        vector<vector<int>>adj(n);
        
        vector<int>inD(n),res;
        
        for(auto x:e){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            inD[x[0]]++;
            inD[x[1]]++;
        }
        
        queue<int>q;
        
       for(int i=0;i<n;i++){
           if(inD[i]==1){
               q.push(i);
               inD[i]=0;
           }
       }
        
        while(!q.empty()){
            
            int sz=q.size();
            res.clear();
            while(sz--){
                int v=q.front();
                q.pop();
                res.push_back(v);
                for(auto x:adj[v]){
                    inD[x]--;
                    if(inD[x]==1)
                        q.push(x);
                }
            }
            
        }
        
       
      if(n==1)return {0};
        
        return res;
        
    }
};