class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
     
        int n=s.length();
        
        vector<vector<int>>res;
        
        int l=0,r=0;
        
        while(r<n){
            
            while(r<n&&s[r]==s[l]){
                r++;
            }
            
            if(r-l>2){
                res.push_back({l,r-1});
            }
            l=r;
        }
        
        return res;
        
    }
};