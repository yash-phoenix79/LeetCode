class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        sort(begin(strs),end(strs));
        string f=strs[0],l=strs[n-1];
        
        int i=0;
        while(i<min(f.length(),l.length())&&f[i]==l[i]){
            ans+=f[i++];
        }
        return ans;
    }
};