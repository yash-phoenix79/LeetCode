class Solution {
public:
    int minGroups(vector<vector<int>>& in) {
        
        int n=in.size();
        sort(begin(in),end(in));
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<in.size();i++){
            if(!pq.empty()&&pq.top()<in[i][0])
                pq.pop();
            pq.push(in[i][1]);
        }
        return pq.size();
    }
};