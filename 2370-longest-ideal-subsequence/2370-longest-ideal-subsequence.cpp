class Solution {
public:
    int longestIdealString(string s, int k) {
        
        int res=0;
        int n=s.length();
        vector<int>dp(26,1);
        
        vector<int>al(26,0);
        
        int i=0;
        
        while(i<n){
            
            char c=s[i];
             int t=c-'a';
            
            if(al[t]>0)
                dp[t]++;
            al[c-'a']++;
            
           
            
            for(int j=1;j<=k;j++){
                if(t-j>=0&&al[t-j]>0){
                    dp[t]=max(dp[t],1+dp[t-j]);
                }
                if(j+t<26&&al[j+t]>0)
                    dp[t]=max(dp[t],1+dp[j+t]);
            }
            
            res=max(res,dp[t]);
            
            // cout<<i<<endl;
            
            i++;
        }
        return res;
        
    }
};