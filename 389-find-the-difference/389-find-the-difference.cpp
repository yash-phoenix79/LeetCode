class Solution {
public:
    char findTheDifference(string s, string t) {
       vector<int>alph(26,0);
        
        for(int i=0;i<t.length();i++)
            alph[t[i]-'a']++;
        for(int i=0;i<s.length();i++)
             alph[s[i]-'a']--;
        char ans;
        for(int i=0;i<26;i++){
            if(alph[i])
               { ans= 'a'+i;
                break;}
        }
        return ans;
    }
};