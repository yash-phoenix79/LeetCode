class Solution {
public:
    int fib(int n) {
        
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        
        int fir=0,sec=1,ans;
        
        n--;
        
        while(n--){
            ans=fir+sec;
            fir=sec;
            sec=ans;
        }
        return ans;
        
    }
};