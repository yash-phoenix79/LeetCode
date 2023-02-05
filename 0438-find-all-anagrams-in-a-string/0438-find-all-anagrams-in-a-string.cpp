class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int n=s.length(),m=p.length();
        
        vector<int>h1(26,0),h2(26,0);
        
        vector<int>res;
        
        if(n<m)
            return res;
        
        int l=0,r=0;
        
        while(r<m){
            
            h1[s[r]-'a']++;
            h2[p[r]-'a']++;
            
            r++;
            
        }
        r--;
        while(r<n){
            
            if(h1==h2)
                 res.push_back(l);
            
            r++;
            if(r<n)
            h1[s[r]-'a']++;
            h1[s[l]-'a']--;    
            l++;
        }
        
        return res;
        
        
    }
};