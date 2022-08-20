class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int i=0;
        int cur=startFuel,n=stations.size();
        int res=0;
        priority_queue<int>pq;
        while(cur<target){
            while(i<n&&stations[i][0]<=cur){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty())
                return -1;
           cur+=pq.top();
            pq.pop();
            res++;
        }
        return res;
    }
};