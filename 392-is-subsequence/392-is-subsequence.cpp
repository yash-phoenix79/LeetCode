class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int n=s.length(),m=t.length();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        
        for(int i=0;i<=m;i++)dp[i][0]=0;
        for(int i=0;i<=n;i++)dp[0][i]=0;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(t[i-1]==s[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=dp[i-1][j];
                    
            }
        }
        
        cout<<dp[m][n];
        
        return dp[m][n]==n;
    }
};