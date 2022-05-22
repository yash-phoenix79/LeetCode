class Solution {
public:
    int countSubstrings(string s) {
        
        int ans=0;
        string t="";
        
        for(int i=0;i<s.length();i++){
            t="";
            for(int j=i;j<s.length();j++){
                t+=s[j];
                string temp=t;
                reverse(temp.begin(),temp.end());
                if(temp==t)
                    ans++;
            }
        }
        return ans;
    }
};