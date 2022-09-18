class Solution {
public:
    int secondHighest(string s) {
        
        int f=-1,s1=-1;
        
        for(auto x:s){
            if(isdigit(x)){
                if(x-'0'>f){
                    s1=f;
                    f=x-'0';
                }
                else if(x-'0'!=f&&x-'0'>s1)
                    s1=x-'0';
            }
        }
        return s1;
        
    }
};