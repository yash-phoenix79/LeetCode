class Solution {
public:
    
    int concatenatedBinary(int n) {
        int l=0;
        int M=1e9 + 7;
        long ans=0;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0)l++;
            ans=((ans<<l)|i)%M;
        }
        return ans;
    }
};