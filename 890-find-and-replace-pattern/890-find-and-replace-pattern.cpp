class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        
        int n=words.size();
        int m=pattern.length();
        
        for(int i=0;i<n;i++){
            vector<int>alph1(26,-1),alph2(26,-1);
            int j;
            for(j=0;j<m;j++){
                if(alph1[words[i][j]-'a']!=alph2[pattern[j]-'a'])
                   break;
                alph1[words[i][j]-'a']=alph2[pattern[j]-'a']=j;
            }
            if(j==m)
            res.push_back(words[i]);
        }
        return res;
    }
};