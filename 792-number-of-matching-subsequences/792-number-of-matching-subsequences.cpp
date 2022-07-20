class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>al(26);
        for(int i=0;i<s.length();i++)
            al[s[i]-'a'].push_back(i);
        
        int res=0;
        for(auto &word:words){
            int x=-1;
            bool find=true;
            for(auto c:word){
                if(!find){
                    break;
                }
                auto it=upper_bound(al[c-'a'].begin(),al[c-'a'].end(),x);
                if(it==al[c-'a'].end())
                    find=false;
                else
                    x=*it;
            }
            if(find)
                res++;
        }
        return res;
    }
};