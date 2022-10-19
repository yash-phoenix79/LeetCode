class Solution {
public:
     
    class myComp{
      public:
        bool operator()(pair<string,int>&a,pair<string,int>&b){
            if(a.second==b.second)
            return a.first>b.first;
            return a.second<b.second;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int>m;
        for(auto x:words)
            m[x]++;
        
        priority_queue<pair<string,int>,vector<pair<string,int>>,myComp>pq;
        
        for(auto x:m){
            pq.push({x.first,x.second});
            cout<<pq.top().first<<" ";
            
        }
        
        vector<string>res;
        while(k--&&!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            res.push_back(cur.first);
        }
        return res;
    }
};