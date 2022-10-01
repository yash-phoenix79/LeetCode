class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
		if(s[0]=='0')
			return 0;
        vector<int> dp(n+1,1);
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0')
                dp[i]=0;
            else if(i!=n-1&&(s[i]=='1'||(s[i]=='2'&&s[i+1]<='6')))
                dp[i]=dp[i+1]+dp[i+2];
            else
                dp[i]=dp[i+1];
        }
        return dp[0];
    }
};