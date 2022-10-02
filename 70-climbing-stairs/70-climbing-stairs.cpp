class Solution {
public:
    int climbStairs(int n) {
        
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        
        int f=1,s=2,t;
        n-=2;
        while(n--){
            t=f+s;
            f=s;
            s=t;
            
        }
        return t;
        
    }
};