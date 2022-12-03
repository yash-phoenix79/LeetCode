class Solution {
public:
    string frequencySort(string s) {
        
        int n=s.length();
        string res="";
        
        unordered_map<char,int>m;
        
        for(auto x:s)
            m[x]++;
        
        vector<pair<int,char>>t;
        for(auto x:m)
            t.push_back({x.second,x.first});
        
        sort(begin(t),end(t),[](auto &a,auto &b){
           return a.first>b.first; 
        });
        
        int i=0;
        while(i<t.size()){
            while(t[i].first--)
            res+=t[i].second;
            i++;
        }
        
            return res;
        
    }
};