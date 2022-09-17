class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int t=n&1;
        n=n>>1;
        
        while(n>0){
            int s=n&1;
            if(s==t)
                return false;
            t=s;
            n=n>>1;
        }
        return true;
    }
};