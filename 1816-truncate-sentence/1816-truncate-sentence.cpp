class Solution {
public:
    string truncateSentence(string s, int k) {
        int n=s.length();
        string t="";
        int i=0;
        int cnt=0;
        string res="";
        while(i<n&&cnt<k){
            t="";
            while(i<n&&s[i]!=' '){
                t+=s[i++];
            }
            i++;
            res+=t;
            res+=" ";
            cnt++;
        }
        int l=res.length();
        return res.substr(0,l-1);
    }
};