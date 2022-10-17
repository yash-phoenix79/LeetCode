int dp[301][11];

class Solution {
public:
    
    int find(int idx,vector<int>& j,int n,int d){
        if(d==1){
            return *max_element(j.begin()+idx,j.end());
        }
        
        if(dp[idx][d]!=-1)
        return dp[idx][d];
        int val=INT_MIN;
        int res=INT_MAX;
        
        for(int i=idx;i<=n-d;i++){
            val=max(val,j[i]);
            res=min(res,val+find(i+1,j,n,d-1));
        }
        return dp[idx][d]=res;
    }
    
    int minDifficulty(vector<int>& j, int d) {
        int n=j.size();
        if(n<d)
            return -1;
        memset(dp,-1,sizeof(dp));
        return find(0,j,n,d);
    }
};