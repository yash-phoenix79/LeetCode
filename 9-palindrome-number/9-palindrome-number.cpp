class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0)
            return false;
        long long cnt=0;
        int t=x;
        while(t){
            cnt=cnt*10+t%10;
            t/=10;
        }
        return x==cnt;
    }
};