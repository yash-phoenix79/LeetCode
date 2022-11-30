class Solution {
public:
  
    bool uniqueOccurrences(vector<int>& arr) {
        int n=size(arr);
        
        unordered_map<int,int>m;
        for(int x:arr)
            m[x]++;
        
        unordered_set<int>s;
        for(auto x:m){
            if(s.find(x.second)!=s.end())
                return false;
            s.insert(x.second);
        }
        
        return true;
    }
};