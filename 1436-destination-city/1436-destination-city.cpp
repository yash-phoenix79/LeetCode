class Solution {
public:
    
    string res;
    
    void dfs(string s,unordered_map<string,string>&m){
        
        if(m[s]=="")
        {
            res=s;
            return;
        }
        
        dfs(m[s],m);
        
    }
    
    string destCity(vector<vector<string>>& paths) {
        
        unordered_map<string,string>m;
        
        for(auto x:paths){
            m[x[0]]=(x[1]);
        }
        
        dfs(paths[0][0],m);
        return res;
    }
};