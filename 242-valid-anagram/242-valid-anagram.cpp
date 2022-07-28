class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map<char,int>m;
        
        for(int i=0;i<s.length();i++)
            m[s[i]]++;
        
        for(int i=0;i<s.length();i++){
            if(m.find(t[i])==m.end())
                return false;
            else if(m[t[i]]==1){
                m.erase(t[i]);
            }
            else
                m[t[i]]--;
        }
        
        return m.empty()?true:false;
        
    }
};