class Solution {
public:
    bool areNumbersAscending(string s) {
        
        int t=INT_MIN;
        
        int i=0;
        
        while(i<s.length()){
            if(s[i]>='0'&&s[i]<='9'){
                int temp=0;
                while(i<s.length()&&(s[i]>='0'&&s[i]<='9'))
                    temp=temp*10+(s[i++]-'0');
                if(temp<=t)
                    return false;
                t=temp;
            }
            i++;
        }
        
        return true;
    }
};