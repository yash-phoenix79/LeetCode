class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        int n=s.length();
        int start=-1;
        int ans=0;
       vector<int>al(256,-1);
        
        for(int i=0;i<n;i++){
            if(al[s[i]-'\0']>start)
                start=al[s[i]-'\0'];
            al[s[i]-'\0']=i;
            ans=max(ans,i-start);
        }
        return ans;
    }
};