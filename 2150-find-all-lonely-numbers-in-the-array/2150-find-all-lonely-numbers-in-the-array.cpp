class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
     
        unordered_map<int,int>m;
        vector<int>res;
        for(auto x:nums)
            m[x]++;
        
        for(auto x:m){
            
            if(x.second==1&&m.find(x.first-1)==m.end()&&m.find(x.first+1)==m.end())
                res.push_back(x.first);
            
        }
        
        return res;
        
    }
};