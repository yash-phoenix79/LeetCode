class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
   
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
      
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0)
                    dp[i][j]=0;
                else if(nums2[i-1]==nums1[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
};