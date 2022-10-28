class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     
        int n=strs.size();
        unordered_map<string,vector<string>>m;
        
        vector<vector<string>>res;
        
        for(auto x:strs){
            
            string t=x;
            sort(t.begin(),t.end());
            m[t].push_back(x);
            
        }
        
        for(auto x:m){
            res.push_back(x.second);
        }
        
        return res;
        
    }
};