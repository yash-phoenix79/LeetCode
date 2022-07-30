class Solution {
public:
    
    vector<int> cntr(string s){
        int n=s.length();
         vector<int>cnt(26,0);
        for(int i=0;i<n;i++)
            cnt[s[i]-'a']++;
     return cnt;       
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
       
         vector<string>res;
        vector<int>cnt(26,0),tmp(26,0);
        
        for(int i=0;i<words2.size();i++){
            tmp=cntr(words2[i]);
             for(int j=0;j<26;j++){
                   if(tmp[j]>cnt[j])
                    cnt[j]=tmp[j];
             }
              
        }
        
        for(int i=0;i<words1.size();i++){
            tmp=cntr(words1[i]);
            int j=0;
            for(j=0;j<26;j++){
                if(tmp[j]<cnt[j])
                break; 
            }
           
            if(j==26)
                res.push_back(words1[i]);
        }
        return res;
    }
};