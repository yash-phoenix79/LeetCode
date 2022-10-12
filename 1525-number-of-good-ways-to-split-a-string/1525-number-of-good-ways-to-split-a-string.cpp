class Solution {
public:
    
    unordered_map<char,int>m1,m2;
    
    int numSplits(string s) {
        int n=s.length();
        
        for(auto x:s)
            m1[x]++;
        int res=0;
        
        for(int i=0;i<n-1;i++){
            if(m1[s[i]]==1)
                m1.erase(s[i]);
            else
                m1[s[i]]--;
            m2[s[i]]++;
            if(m1.size()==m2.size())res++;
        }
        return res;
    }
};