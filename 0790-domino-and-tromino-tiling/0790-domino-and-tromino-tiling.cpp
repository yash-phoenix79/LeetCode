class Solution {
public:
    
    #define N 1000000007
    
    int numTilings(int n) {
        
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(n==3)
            return 5;
        
        long long int f=1,s=2,t=5;
        n-=3;
        
         long long int res;
        
        while(n--){
            
            res=(2*(t%N)+f%N)%N;
            f=s;
            s=t;
            t=res;
            
        }
        
        return res%N;
        
        
    }
};