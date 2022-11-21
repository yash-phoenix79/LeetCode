class Solution {
public:
    bool areAlmostEqual(string s, string g) {
        
        
        if(s.length()!=g.length())
            return false;
        
        if(s==g)
            return true;
        
        vector<int>t;
        
        for(int i=0;i<s.length();i++){
            
            if(s[i]!=g[i]){
                t.push_back(i);
                if(t.size()>2)
                    return false;
            }
            
        }
        
        if(t.size()==1)
            return false;
        
        
        swap(s[t[0]],s[t[1]]);
        return s==g;
        
        
    }
};