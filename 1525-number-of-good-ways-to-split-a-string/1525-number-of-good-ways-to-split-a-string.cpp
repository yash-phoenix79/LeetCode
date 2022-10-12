class Solution {
public:
    int numSplits(string s) {
        
        int n=s.length();
        vector<int>m1(26,0),m2(26,0);
        
        int res=0,dr=0,dl=0;
        for(auto x:s){
            dr+= ++m1[x-'a']==1;
        }
        
        for(int i=0;i<n-1;i++){
            dl+= ++m2[s[i]-'a']==1;
            dr-= --m1[s[i]-'a']==0;
            res+=dl==dr;
        }
        return res;
    }
};