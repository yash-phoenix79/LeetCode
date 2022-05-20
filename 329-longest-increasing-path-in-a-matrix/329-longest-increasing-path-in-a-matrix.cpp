class Solution {
public:
    int maxLen=0;
    int d[5]={1,0,-1,0,1};
    int findPath(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& mat){
        int n=size(mat),m=size(mat[0]);
        if(dp[i][j]!=-1)
            return dp[i][j];
        int t=1;
        for(int k=0;k<4;k++){
            int newX=i+d[k],newY=j+d[k+1];
            if(newX<0||newX>=n||newY<0||newY>=m||mat[newX][newY]<=mat[i][j])
                continue;
            t=max(t,1+findPath(newX,newY,dp,mat));
        }
        return dp[i][j]=t;
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxLen=max(maxLen,findPath(i,j,dp,mat));
            }
        }
        return maxLen;
    }
};