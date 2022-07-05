class Solution {
public:
    long long waysToBuyPensPencils(int t, int c1, int c2) {
        
        long long cnt=t/c1;
        long long res=0;
        
        for(long long i=0;i<=cnt;i++){
            long long rem=t-(i)*c1;
            long long cnt2=rem/c2;
            res+=(cnt2+1);
        }
        
        return res;
        
    }
};