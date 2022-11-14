class Solution {
public:
    
    unordered_map<string,vector<pair<string,double>>>gph;
    unordered_map<string,bool>vis;
    
    double queryAns;
    
    bool dfs(string cur,string end,double prod){
        
        if(cur==end&&gph.find(cur)!=gph.end()){
            queryAns=prod;
            return true;
        }
        
        vis[cur]=true;
        bool tempAns=false;
        
        for(auto x:gph[cur]){
            if(!vis[x.first])
                tempAns=dfs(x.first,end,prod*x.second);
            if(tempAns)
                break;
        }
        
        vis[cur]=false;
        return tempAns;
        
    }
    
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
        
        int n=eq.size();
        int m=q.size();
        
        for(int i=0;i<n;i++){
            gph[eq[i][0]].push_back({eq[i][1],val[i]});
            gph[eq[i][1]].push_back({eq[i][0],1/val[i]});
            vis[eq[i][0]]=false;
            vis[eq[i][1]]=false;
        }
        
        vector<double>res(m);
        
        for(int i=0;i<m;i++){
            queryAns=1;
            if(dfs(q[i][0],q[i][1],1.0))
                res[i]=queryAns;
            else
                res[i]=-1.0;
        }
        
        return res;
        
    }
};