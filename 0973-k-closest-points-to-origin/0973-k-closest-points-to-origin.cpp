class Solution {
public:
    
    class myComp{
      public:
        bool operator()(pair<float,pair<int,int>>&a,pair<float,pair<int,int>>&b){
            
            return a.first>b.first;
            
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>res;
        
        priority_queue<pair<float,pair<int,int>>,vector<pair<float,pair<int,int>>>,myComp>pq;
        
        for(auto t:points){
            
            int x=t[0];
            int y=t[1];
            float dis=x*x+y*y;
            dis=sqrt(dis);
            pq.push({dis,{x,y}});
            // if(pq.size()>k)
            //     pq.pop();
        }
        
        while(k--&&!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            int x=cur.second.first;
            int y=cur.second.second;
            res.push_back({x,y});
        }
        return res;
    }
};