class Solution {
public:
   vector<vector<int>>dp;
    
    int find(int idx,int ac,int bc,vector<vector<int>>& costs){
        
        int n=costs.size();
        if(idx>=n)return 0;
        
        if(dp[ac][bc]!=-1)
            return dp[ac][bc];
        
        int t=n/2;
        
     int ans1=INT_MAX,ans2=INT_MAX;
        
        if(ac<t)
             ans1=costs[idx][0]+find(idx+1,ac+1,bc,costs);
        
        
        if(bc<t)
             ans2=costs[idx][1]+find(idx+1,ac,bc+1,costs);
        
        return dp[ac][bc]=min(ans1,ans2);
        
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n=costs.size();
        int t=n/2;
        
        dp=vector<vector<int>>(t+2,vector<int>(t+2,-1));
        
        int ac=0,bc=0;
        return find(0,ac,bc,costs);
        
    }
};