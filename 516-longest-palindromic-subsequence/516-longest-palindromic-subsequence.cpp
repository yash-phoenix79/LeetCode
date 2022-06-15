class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>>dp(2,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            dp[i&1][i]=1;
            for(int j=i-1;j>=0;j--){
                if(s[j]==s[i])
                    dp[i&1][j]=2+dp[(i-1)&1][j+1];
                else
                    dp[i&1][j]=max(dp[(i-1)&1][j],dp[i&1][j+1]);
            }
        }
        return dp[(n-1)&1][0];
    }
};