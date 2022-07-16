class Solution {
public:
    #define M 1000000007
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
    int find(int m,int n,int move,int n1,int x,int y, vector<vector<vector<int>>>&dp){
        if(x<0||y<0||x>=m||y>=n)
            return 1;
        if(n1==move)
            return 0;
        if(dp[n1][x][y]!=-1)
            return dp[n1][x][y];
        
        int ans=0;
        for(int i=0;i<4;i++){
            int X=x+dx[i];
            int Y=y+dy[i];
            ans=(ans%M)+find(m,n,move,n1+1,X,Y,dp)%M;
        }
        
        return dp[n1][x][y]=ans;        
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
       vector<vector<vector<int>>>dp(maxMove,vector<vector<int>>(m,vector<int>(n,-1)));
        
        return find(m,n,maxMove,0,startRow,startColumn,dp)%M;
        
    }
};