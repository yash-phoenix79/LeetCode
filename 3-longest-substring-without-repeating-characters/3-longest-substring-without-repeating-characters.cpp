class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen=0,start=-1;
        vector<int>dict(256,-1);
        
      for(int i=0;i<s.length();i++){
          if(dict[s[i]]>start){
              start=dict[s[i]];
          }
          dict[s[i]-'\0']=i;
          maxLen=max(maxLen,i-start);
      }  
        return maxLen;
    }
};