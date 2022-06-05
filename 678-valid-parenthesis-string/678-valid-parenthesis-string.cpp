class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int cnt=0,t=0;
        for(int i=0;i<n;i++){
            if(s[i]==')')
                cnt--;
            else if(s[i]=='(')
                cnt++;
            else
                t++;
            if(cnt+t<0)return false;
        }
        
        cnt=0,t=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(')
                cnt--;
            else if(s[i]==')')
                cnt++;
            else
                t++;
            if(cnt+t<0)return false;
        }
        return true;
    }
};