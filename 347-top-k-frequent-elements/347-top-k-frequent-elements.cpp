class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        
        for(auto x:m){
            pq.push(make_pair(x.second,x.first));
            
        }
        
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};