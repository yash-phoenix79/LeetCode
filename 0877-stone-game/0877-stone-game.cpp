class Solution {
public:
    
    int dp[502][502][2];
    
    int find(vector<int>&piles,int l,int r,int tak){
        
        if(l>r)
            return 0;
        
        if(dp[l][r][tak]!=-1)
            return dp[l][r][tak];
        
        int res;
        if(tak)
             res=max(piles[l]+find(piles,l+1,r,0),piles[r]+find(piles,l,r-1,0));
        else
            res=min(piles[l]+find(piles,l+1,r,1),piles[r]+find(piles,l,r-1,1));
        
        return dp[l][r][tak]=res;
    }
    
    bool stoneGame(vector<int>& piles) {
     
        int n=piles.size();
        int sum=0;
        for(auto x:piles)
            sum+=x;
        
        
        memset(dp,-1,sizeof(dp));
        int al=find(piles,0,n-1,1);    
        
        if(al>sum/2)
            return true;
        return false;
        
    }
};