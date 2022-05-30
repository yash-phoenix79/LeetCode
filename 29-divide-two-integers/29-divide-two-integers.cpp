class Solution {
public:
    int divide(int dividend, int divisor) {
        
        long long ans=(long long)dividend/divisor;
        if(ans>INT_MAX)
            ans=INT_MAX;
        if(ans<INT_MIN)
            ans=INT_MIN;
        
        return (int)ans;
    }
};