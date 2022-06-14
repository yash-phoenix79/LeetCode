class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size()>word2.size())
            swap(word1,word2);
        int m=word1.size(),n=word2.size();
        vector<vector<int>>dp(2,vector<int>(m+1));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0)
                    dp[i&1][j]=0;
                else if(word1[j-1]==word2[i-1])
                    dp[i&1][j]=1+dp[(i-1)&1][j-1];
                else
                    dp[i&1][j]=max(dp[i&1][j-1],dp[(i-1)&1][j]);
            }
        }
        return m+n-2*dp[n&1][m];
    }
};