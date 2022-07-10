class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int f=cost[0],s=cost[1];
        int res;
        for(int i=2;i<n;i++){
            res=cost[i]+min(f,s);
            f=s;
            s=res;
        }
        return min(f,s);
    }
};