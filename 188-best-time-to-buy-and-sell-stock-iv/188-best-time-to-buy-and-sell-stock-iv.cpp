class Solution {
public:
    int maxProfit(int k, vector<int>& pri) {
        
        int n=pri.size();
        if(k==0||n<=1)
            return 0;
        
        else if(2*k>=n){
            int res=0;
            for(int i=1;i<n;i++){
                if(pri[i]>pri[i-1])
                    res+=(pri[i]-pri[i-1]);
            }
            return res;
        }
        
        vector<int>dp(2*k);
        for(int i=0;i<2*k;i++)
        {
            if(i%2)
                dp[i]=0;
            else
                dp[i]=INT_MIN;
        }
        
        for(int j=0;j<n;j++){
            
            for(int i=0;i<2*k;i++){
                if(i==0)
                    dp[i]=max(dp[i],-pri[j]);
                else if(i%2==0)
                    dp[i]=max(dp[i],dp[i-1]-pri[j]);
                else
                    dp[i]=max(dp[i],dp[i-1]+pri[j]);
            }
            
        }
        
        return dp[2*k-1];
        
    }
};