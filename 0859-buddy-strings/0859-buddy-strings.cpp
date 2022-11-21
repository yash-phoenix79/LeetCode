class Solution {
public:
    bool buddyStrings(string s, string g) {
        
        unordered_set<char>m;
        
        if(s.length()!=g.length())
            return false;
        
        vector<int>t;
        
        for(int i=0;i<s.length();i++){
            
            if(s[i]!=g[i]){
                t.push_back(i);
                if(t.size()>2)
                    return false;
            }
           
            m.insert(s[i]);
            
        }
        
        if(t.size()==1)
            return false;
        if(t.size()==0){
            if(m.size()==s.length())return false;
            return true;
        }
        
        swap(s[t[0]],s[t[1]]);
        return s==g;
        
    }
};