class Solution {
public:
    bool wordPattern(string p, string s) {
        
        unordered_map<string,int>m1;
        unordered_map<char,int>m2;
        
        stringstream x(s);
        
        string t;
        
        int i=0,n=p.length();
        
        while(getline(x,t,' ')){
            
            if(i==n)return false;
            
            if(m2[p[i]]!=m1[t])return false;
            
            m2[p[i]]=m1[t]=i+1;
            i++;
            
        }
        return i==n;
        
    }
};