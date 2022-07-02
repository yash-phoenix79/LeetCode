class Solution {
public:
    string longestPrefix(string s) {
        
        int n=s.length();
        vector<int>ans(n,0);
        int j=0,i=1;
        
        while(i<n){
            if(s[i]==s[j]){
                ans[i]=j+1;
                i++,j++;
            }
            else{
                if(j==0){
                    ans[i]=0;
                    i++;
                }
                else
                    j=ans[j-1];
            }
        }
        
        int l=ans.back();
        return s.substr(0,l);
        
    }
};