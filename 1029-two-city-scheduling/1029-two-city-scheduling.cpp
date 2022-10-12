class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
     
        int n=costs.size();
        sort(begin(costs),end(costs),[](auto &a,auto &b){
           return a[0]-a[1]<b[0]-b[1]; 
        });
        
        int res=0;
        for(int i=0;i<n/2;i++){
            res+=costs[i][0];
            res+=costs[i+n/2][1];
        }
        return res;
    }
};