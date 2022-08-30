class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        long long tar=(1<<n)-1;
        queue<pair<int,pair<int,long long>>>q;
        set<pair<int,long long>>s;
        
        for(int i=0;i<n;i++){
            q.push({i,{0,1<<i}});
            s.insert({i,1<<i});
        }
        
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            int node=cur.first;
            int dis=cur.second.first;
            long long mask=cur.second.second;
            
            for(auto x:graph[node]){
                long long newMask=mask|(1<<x);
                if(newMask==tar)
                    return dis+1;
                else if(s.find({x,newMask})!=s.end())
                    continue;
                else{
                    q.push({x,{dis+1,newMask}});
                    s.insert({x,newMask});
                }
            }
            
        }
        return 0;
        
    }
};