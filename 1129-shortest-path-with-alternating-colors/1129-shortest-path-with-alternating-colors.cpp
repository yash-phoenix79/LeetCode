class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& re, vector<vector<int>>& bl) {
        
        vector<vector<pair<int,int>>>g(n);
        for(auto &x:re)g[x[0]].push_back({x[1],0});
        for(auto &x:bl)g[x[0]].push_back({x[1],1});
        
        vector<vector<int>>dis(n,vector<int>(2,-1));
        queue<pair<int,int>>q;
        q.push({0,0});
        q.push({0,1});
        
        dis[0]={0,0};
        
        while(!q.empty()){
            auto [i,c1]=q.front();
            q.pop();
            for(auto [j,c2]:g[i]){
                if(dis[j][c2]!=-1||c1==c2)
                    continue;
                dis[j][c2]=1+dis[i][c1];
                q.push({j,c2});
            }
        }
        
        vector<int>res;
        for(auto &v:dis)
        {
            sort(v.begin(),v.end());
            res.push_back(v[0]==-1?v[1]:v[0]);
        }
        return res;
    }
};