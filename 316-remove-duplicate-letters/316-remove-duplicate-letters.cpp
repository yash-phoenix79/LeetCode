class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();
        vector<int>last(26),seen(26,0);
        
        for(int i=0;i<n;i++)
            last[s[i]-'a']=i;
        
        string res="";
        
        for(int i=0;i<n;i++){
            if(seen[s[i]-'a']++)continue;
            while(!res.empty()&&res.back()>s[i]&&last[res.back()-'a']>i){
                seen[res.back()-'a']=0;
                res.pop_back();
            }
            res.push_back(s[i]);
        }
        return res;
    }
};