class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int start=-1;
        int maxLen=0;
        vector<int>dict(256,-1);
        
        for(int i=0;i<n;i++){
            if(dict[s[i]]>start)
            {
                start=dict[s[i]];
            }
            dict[s[i]]=i;
            maxLen=max(maxLen,i-start);
        }
        return maxLen;
    }
};