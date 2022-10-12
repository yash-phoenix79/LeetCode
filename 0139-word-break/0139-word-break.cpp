class Solution {
public:
    bool wordBreak(string s, vector<string>& w) {
        
        int n=s.length();
        
        vector<bool>dp(n+1,false);
        dp[0]=true;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j]&&find(w.begin(),w.end(),s.substr(j,i-j))!=w.end())
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
        
    }
};