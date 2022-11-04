class Solution {
public:
    string reverseVowels(string s) {
        
        string v="";
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                v+=s[i];
            }
        }
        
        int m=v.length();
        int j=m-1;
        for(int i=0;i<n;i++){
              if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                 s[i]=v[j--];
             }
        }
        
        return s;
        
    }
};