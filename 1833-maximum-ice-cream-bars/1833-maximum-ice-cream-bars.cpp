class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int res=0;
        int n=costs.size();
        sort(costs.begin(),costs.end());
        int i=0;
        while(i<n&&coins-costs[i]>=0){
            res++;
            coins-=costs[i++];
        }
        return res;
    }
};