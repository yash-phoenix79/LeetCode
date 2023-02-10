class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n=arr.size();
        vector<int>res;
        
        vector<pair<int,int>>t(n);
        for(int i=0;i<n;i++)
            t[i]={arr[i],i};
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(auto x:t)
            pq.push(x);
        
        int r=0;
        
        int temp=INT_MIN;
        
        while(!pq.empty()){
            
            auto cur=pq.top();
            pq.pop();
            int e=cur.first;
            int idx=cur.second;
            
            if(e!=temp){
                temp=e;
                ++r;
                
            }
           
               arr[idx]=r;
            
            
        }
        
        return arr;
        
    }
};