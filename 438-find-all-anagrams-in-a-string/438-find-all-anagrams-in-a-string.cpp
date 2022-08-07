class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(p.size()>s.size())
            return ans;
        unordered_map<char,int>m1,m2;
        for(int i=0;i<p.size();i++)
            m1[p[i]]++;
        
        for(int i=0;i<p.size();i++){
           m2[s[i]]++;
        }
            
        int i=0,j=p.size()-1;
        
        while(j<s.size()){
            if(m1==m2){
                ans.push_back(i);
            }
           if(m2[s[i]]==1)
               m2.erase(s[i++]);
            else
                m2[s[i++]]--;
            j++;
            if(j<s.size())
                m2[s[j]]++;
        }
        return ans;
    }
};