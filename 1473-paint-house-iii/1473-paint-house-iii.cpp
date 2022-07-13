class Solution {
public:
    int dp[101][21][101];
    int help(int i,int col,int neigh,vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target)
    {
    if(neigh>target)
        return INT_MAX/2;
        
        if(i==m){
            return neigh==target?0:INT_MAX/2;
        }
        if(dp[i][col][neigh]!=-1)return dp[i][col][neigh];
        int ans=INT_MAX/2;
        if(houses[i]==0){
            
            for(int j=0;j<n;j++){
                ans=min(ans,cost[i][j]+help(i+1,j+1,(col==j+1)?neigh:neigh+1,houses,cost,m,n,target));
            }
        }
        else
            ans=min(ans,help(i+1,houses[i],(col==houses[i])?neigh:neigh+1,houses,cost,m,n,target));
        return dp[i][col][neigh]=ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans=help(0,0,0,houses,cost,m,n,target);
        return ans==INT_MAX/2?-1:ans;
        
    }
};