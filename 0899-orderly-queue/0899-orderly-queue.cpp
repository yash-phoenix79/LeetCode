class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        if(k>1)
        {
            sort(begin(s),end(s));
            return s;
        }
        int n=s.length();
        string res=s;
        for(int i=1;i<n;i++){
            res=min(res,s.substr(i)+s.substr(0,i));
        }
        return res;
    }
};