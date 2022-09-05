class Solution {
public:
    
    int find(vector<int>&arr,int l,int r,vector<vector<int>>&dp){
        if(l==r)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        
        int res=INT_MAX;
        for(int i=l;i<r;i++)
            res=min(res,*max_element(arr.begin()+l,arr.begin()+i+1)*(*max_element(arr.begin()+i+1,arr.begin()+r+1))+find(arr,l,i,dp)+find(arr,i+1,r,dp));
        return dp[l][r]=res;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return find(arr,0,n-1,dp);
        
    }
};