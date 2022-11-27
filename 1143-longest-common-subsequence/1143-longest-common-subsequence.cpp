class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        
        int n=t1.length(),m=t2.length();
        if(n>m){
            swap(t1,t2);
        }
        n=t1.length(),m=t2.length();
        
        vector<vector<int>>dp(2,vector<int>(n+1));
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(!i||!j)
                    dp[i&1][j]=0;
                else if(t2[i-1]==t1[j-1])
                    dp[i&1][j]=1+dp[(i-1)&1][j-1];
                else
                    dp[i&1][j]=max(dp[(i-1)&1][j],dp[(i)&1][j-1]);
            }
        }
        
        return dp[m&1][n];
        
    }
};