class Solution {
public:
    
    int findPath(int i,int j,int m,int n,vector<vector<int>>&dp){
    
        if(i>=m||j>=n)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        if(i==m-1&&j==n-1){
              
            return 1;
        }
        
        
         ans+= findPath(i+1,j,m,n,dp);
       ans+= findPath(i,j+1,m,n,dp);
        
        return dp[i][j]=ans;
        
    }
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        int i=0,j=0;
        return findPath(i,j,m,n,dp);
        
    }
};