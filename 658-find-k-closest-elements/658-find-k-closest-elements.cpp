class Solution {
public:
    
    class myComp{
        public:
      bool operator()(const pair<int,int> &a,const pair<int,int> &b){
           if(a.second==b.second)
                return a.first<b.first;
            return a.second<b.second;
      }  
    };
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,myComp>pq;
            
            for(int i=0;i<n;i++){
                pair<int,int>p={arr[i],abs(arr[i]-x)};
             pq.push(p);
                if(pq.size()>k)
                    pq.pop();
            }
        
        vector<int>res;
        while(!pq.empty())
        {
            res.push_back(pq.top().first);
            pq.pop();
        }    
        sort(begin(res),end(res));
        return res;
    }
};