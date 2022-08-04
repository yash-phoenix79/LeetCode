class Solution {
public:
    int climbStairs(int n) {
     
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        
        int fir=1,sec=2;
        
        int ans;
        
        for(int i=0;i<n-2;i++){
            ans=fir+sec;
            fir=sec;
            sec=ans;
        }
        return ans;
    }
};