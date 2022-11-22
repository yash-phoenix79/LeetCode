class Solution {
public:
    
    vector<int>dp;
    int x;
    
    int find(int n,int x){
        
         if(n<0)
            return INT_MAX/2;
        
        if(n==0)
            return 0;
        
        if(dp[n]!=-1)
            return dp[n];
        
        int res=INT_MAX/2;
        
        for(int i=1;i<=x;i++)
            res=min(res,1+find(n-i*i,x));
        
        return dp[n]=res;
        
    }
    
    int numSquares(int n) {
        
        x=sqrt(n);
        
        dp=vector<int>(n+1,-1);
        
        for(int i=0;i<=x;i++)
            dp[i*i]=1;
        
        
        return find(n,x);
        
    }
};