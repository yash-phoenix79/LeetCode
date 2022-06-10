class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int>ch(256,-1);
        int start=-1,maxLen=0;
        for(int i=0;i<s.length();i++){
            
            if(start<ch[s[i]-'\0'])
                start=ch[s[i]-'\0'];
            maxLen=max(maxLen,i-start);
            ch[s[i]-'\0']=i;
        }
        return maxLen;
    }
};