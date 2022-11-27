class Solution {
public:
    
    int lcs(string t1,string t2){
        
        int n=t1.length();
        vector<vector<int>>dp(2,vector<int>(n+1));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
             if(!i||!j)
                 dp[i&1][j]=0;
                
                else if(t1[i-1]==t2[j-1])
                    dp[i&1][j]=1+dp[(i-1)&1][j-1];
                else
                    dp[i&1][j]=max(dp[(i-1)&1][j],dp[(i)&1][j-1]);
            }
        }
        
        return dp[n&1][n];
        
    }
    
    int longestPalindromeSubseq(string s) {
        
        string t=s;
        reverse(begin(s),end(s));
        
        return lcs(t,s);
        
    }
};