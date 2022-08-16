class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>>m;
        for(int i=0;i<s.length();i++){
            m[s[i]].first++;
            m[s[i]].second=i;
        }
        
        int res=s.length();
        for(auto &[a,b]:m){
            if(b.first==1)
                res=min(res,b.second);
        }
        return res==s.length()?-1:res;
    }
};