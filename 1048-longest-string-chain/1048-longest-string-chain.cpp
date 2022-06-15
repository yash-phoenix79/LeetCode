class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int res=1,n=words.size();
        
        sort(words.begin(),words.end(),[](const string &a,const string &b){
           return a.length()<b.length(); 
        });
    
        unordered_map<string,int>dp;
        
        for(auto i:words)
        {
            dp[i]=1;
            for(auto j=0;j<i.size();j++)
            {
                string pre=i.substr(0,j)+i.substr(j+1);
                if(dp.find(pre)!=dp.end())
                {
                    dp[i]=max(dp[i],dp[pre]+1);
                    res=max(res,dp[i]);
                   
                }
            }
        }
        return res;
    }
    
};