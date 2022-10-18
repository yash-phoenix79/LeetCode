class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
     
        vector<int>ugly(n,0);
        vector<int>p(primes.size(),0);
        ugly[0]=1;
        
        for(int i=1;i<n;i++){
            
            long long mn=INT_MAX;
            for(int j=0;j<primes.size();j++)
                mn=min(mn,(long long)primes[j]*(long long)ugly[p[j]]);
            ugly[i]=mn;
            for(int j=0;j<primes.size();j++)
            {
                if((long long)primes[j]*(long long)ugly[p[j]]==mn)
                    p[j]++;
            }
        }
        return ugly[n-1];
        
    }
};