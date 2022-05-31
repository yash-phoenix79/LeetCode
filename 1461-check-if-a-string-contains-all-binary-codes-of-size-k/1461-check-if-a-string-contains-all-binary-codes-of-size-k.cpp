class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.length();
       
        unordered_map<string,int>m;
        
       for(int i=0;i<=n-k;i++){
           if(!m[s.substr(i,k)])
               m[s.substr(i,k)]++;
       }
        
        if(m.size()==1<<k)
        return true;
        return false;
    }
};