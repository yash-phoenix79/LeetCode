class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string ans="";
        string a=strs[0],b=strs[n-1];
        
        int i=0;
        
        while(a[i]==b[i]&&i<min(a.length(),b.length()))
        {
            ans+=a[i];
            i++;
        }
        return ans;
    }
};