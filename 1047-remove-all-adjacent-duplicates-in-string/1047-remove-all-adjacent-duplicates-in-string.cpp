class Solution {
public:
    string removeDuplicates(string s) {
        
        int n=s.length();
        string res="";
        
        for(int i=0;i<n;i++){
            if(res.empty()||res.back()!=s[i])
                res+=s[i];
            else
                res.pop_back();
        }
        
        return res;
        
    }
};