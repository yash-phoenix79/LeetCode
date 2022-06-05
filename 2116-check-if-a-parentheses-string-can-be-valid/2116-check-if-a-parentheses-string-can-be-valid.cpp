class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=size(s);
        if(n%2)return false;
        int lo=0,lc=0,uo=0,uc=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==')'){
                if(locked[i]=='1')
                    lc++;
                else
                    uc++;
            }
            else{
                if(locked[i]=='1')
                    lo++;
                else
                    uo++;
            }
            if(lc>(lo+uc+uo))
                return false;
        }
        
        lo=0,lc=0,uo=0,uc=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='('){
                if(locked[i]=='1')
                    lo++;
                else
                    uo++;
            }
            else{
                if(locked[i]=='1')
                    lc++;
                else
                    uc++;
            }
             if(lo>(lc+uo+uc))
            return false;
        }
       return true;
    }
};