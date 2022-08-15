class Solution {
public:
    
    string findDecode(string s,int &i){
        string res="";
        while(i<s.length()&&s[i]!=']'){
            if(!isdigit(s[i]))
                res+=s[i++];
            else{
                int n=0;
                while(i<s.length()&&isdigit(s[i]))
                    n=n*10+s[i++]-'0';
                i++;
                string temp=findDecode(s,i);
                i++;
                while(n--)
                    res+=temp;
            }
        }
        return res;
    }
    
    string decodeString(string s) {
        int i=0;
        return findDecode(s,i);
    }
};