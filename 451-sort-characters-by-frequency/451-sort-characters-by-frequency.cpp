class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        vector<pair<char,int>>alp;
       unordered_map<char,int>m;
        for(auto x:s)
            m[x]++;
        
        for(auto [a,b]:m)
            alp.push_back({a,b});
        
        sort(alp.begin(),alp.end(),[](const auto &a,const auto &b){
           return a.second>b.second; 
        });
        
        int i=0;
        string temp="";
        while(i<alp.size()){
            while(alp[i].second--)
                temp+=alp[i].first;
            i++;
        }
        return temp;
    }
};