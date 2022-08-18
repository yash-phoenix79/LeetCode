class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++)
            m[arr[i]]++;
        priority_queue<int>pq;
        for(auto x:m)
            pq.push(x.second);
        int res=0,t=arr.size();
        while(!pq.empty()&&t>arr.size()/2){
            t-=pq.top();
            pq.pop();
            res++;
        }
        return res;
    }
};