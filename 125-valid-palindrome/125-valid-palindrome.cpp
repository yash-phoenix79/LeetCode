class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        string t="";
        for(int i=0;i<n;i++){
           
            if(isupper(s[i]))
                t+=tolower(s[i]);
            else if(islower(s[i]))
                t+=s[i];
            else if(s[i]>='0'&&s[i]<='9')
                t+=s[i];
            else
                continue;
        }
        
        string temp=t;
        reverse(t.begin(),t.end());
        if(temp==t)
            return true;
        return false;
        
    }
};