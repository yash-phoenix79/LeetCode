class Solution {
public:
    
    long counter(int n){
        long res=0;
        for(;n;n/=10)
            res+=pow(10,n%10);
        return res;
    }
    
    bool reorderedPowerOf2(int n) {
        long res=counter(n);
        for(int i=0;i<32;i++)
            if(counter(1<<i)==res)
                return true;
        return false;
    }
};