class Solution {
public:
    bool isSameAfterReversals(int num) {
        
        if(num==0)
            return true;
        int t=num%10;
        return t>0;
        
    }
};