class Solution {
public:
    
    int find(vector<int>& arr,map<pair<int,int>,int>&m,int l,int r,vector<vector<int>>&dp){
        if(l==r)
            return 0;
        
        if(dp[l][r]!=-1)
            return dp[l][r];
        
        int res=INT_MAX;
        for(int i=l;i<r;i++)
        res=min(res,m[{l,i}]*m[{i+1,r}]+find(arr,m,l,i,dp)+find(arr,m,i+1,r,dp));
        return dp[l][r]=res;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        map<pair<int,int>,int>m;
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        for(int i=0;i<n;i++){
            m[{i,i}]=arr[i];
            for(int j=i+1;j<n;j++)
                m[{i,j}]=max(arr[j],m[{i,j-1}]);
        }
        
        return find(arr,m,0,n-1,dp);
        
    }
};