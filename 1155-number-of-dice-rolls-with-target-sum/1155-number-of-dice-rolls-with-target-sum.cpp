class Solution {
public:
    
    #define N 1000000007
    
    int numRollsToTarget(int n, int k, int t) {
        
        vector<vector<int>>dp(n+1,vector<int>(t+1,0));
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=t;j++){
                for(int l=1;l<=k;l++){
                    if(l<=j)
                    dp[i][j]=(dp[i][j]%N+dp[i-1][j-l]%N)%N;
                }
            }
        }
        return dp[n][t];
    }
};