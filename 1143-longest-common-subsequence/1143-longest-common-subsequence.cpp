class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size()>text2.size())
            swap(text1,text2);
        int m=text1.length(),n=text2.length();
        
        vector<vector<int>>dp(2,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(!i||!j)
                    dp[i&1][j]=0;
                else if(text1[j-1]==text2[i-1])
                    dp[i&1][j]=1+dp[(i-1)&1][j-1];
                else
                    dp[i&1][j]=max(dp[(i-1)&1][j],dp[i&1][j-1]);
            }
        }
        return dp[n&1][m];
    }
};