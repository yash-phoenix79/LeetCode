class Solution {
public:
    #define N 1000000007
   
    
    vector<vector<long long>>dp;
    
    long long find(int idx,int n,int k,int t){
        
        if(t<0)
            return 0;
        if(t==0&&idx!=n)
            return 0;
        if(idx==n){
            if(t==0)
                return 1;
            return 0;
        }
        
        long long res=0;
        
        if(dp[idx][t]!=-1)
            return dp[idx][t];
        
        for(int i=1;i<=k;i++){
            res=(res%N+find(idx+1,n,k,t-i)%N)%N;
        }
        
        return dp[idx][t]=res%N;
        
    }
    
    int numRollsToTarget(int n, int k, int tar) {
           
        
        dp=vector<vector<long long>>(n+1,vector<long long>(tar+1,-1));
        
        return (int)find(0,n,k,tar)%N;
    }
};