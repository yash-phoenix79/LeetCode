class Solution {
public:
    
    int dp[601][101][101]={};
    
    int findAns(vector<pair<int,int>>&p,int m,int n,int idx){
        
        if(idx==p.size()||(m==0&&n==0))return 0;
        if(dp[idx][m][n]!=-1)
            return dp[idx][m][n];
        
        if(m<p[idx].first||n<p[idx].second)
        return dp[idx][m][n]=findAns(p,m,n,idx+1);
        
        int take=1+findAns(p,m-p[idx].first,n-p[idx].second,idx+1);
        int notTake=findAns(p,m,n,idx+1);
        
        return dp[idx][m][n]=max(take,notTake);
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int,int>>p;
        memset(dp,-1,sizeof(dp));
        for(auto i:strs){
            int ones=0,zeroes=0;
            for(auto j:i){
                if(j=='0')zeroes++;
                else ones++;
                    
            }
            p.push_back({zeroes,ones});
        }
        return findAns(p,m,n,0);
    }
};