class Solution {
public:
    int minimumCost(vector<int>& cost) {
        priority_queue<int>pq;
        
        for(int i=0;i<cost.size();i++)
            pq.push(cost[i]);
        
        int res=0;
        while(!pq.empty()){
            res+=pq.top();
            pq.pop();
            if(!pq.empty())
            {
                res+=pq.top();
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop();
            }
        }
        return res;
    }
};