class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.length();
       
        unordered_set<string>m;
        
       for(int i=0;i<=n-k;i++){
          m.insert(s.substr(i,k));
           
       }
        
        if(m.size()==1<<k)
        return true;
        return false;
    }
};