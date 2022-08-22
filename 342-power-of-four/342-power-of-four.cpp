class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)
            return true;
        if(n%4||n<=0)
            return false;
        int a=ceil(sqrt(n));
        int b=floor(sqrt(n));
        if(a!=b)
            return false;
        return !(a&(a-1));
    }
};