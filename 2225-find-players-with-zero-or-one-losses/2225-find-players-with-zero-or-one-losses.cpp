class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
        
         vector<vector<int>>res;
        int n=mat.size();
        
        unordered_map<int,int>m;
        unordered_set<int>s;
        
        for(auto x:mat){
            s.insert(x[0]);
            m[x[1]]++;
        }
            
        for(auto x:mat){
            
            if(s.find(x[1])!=s.end())
                s.erase(x[1]);
            
        }
        
        vector<int>a,b;
        
        for(auto x:s)
            a.push_back(x);
        
        for(auto x:m){
            if(x.second==1)
                b.push_back(x.first);
        }
        
        sort(begin(a),end(a));
        sort(begin(b),end(b));
        
        return {a,b};
        
    }
};