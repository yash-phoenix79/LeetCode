class Solution {
public:
    
    int find(int n,vector<int>&dp,int x){
        if(n<0)
            return INT_MAX/2;
        if(n==0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int res=INT_MAX/2;
        for(int i=1;i<=x;i++){
            res=min(res,1+find(n-i*i,dp,x));
        }
   
        return dp[n]=res;
    }
    
    int numSquares(int n) {
        int x=floor(sqrt(n));
    
        vector<int>dp(n+1,-1);
        for(int i=1;i<=x;i++){
            dp[i*i]=1;
        }
        dp[0]=0;
        
        return find(n,dp,x);
        
        
    }
};