class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        
        int n=b.size();
        
        vector<int>res(n);
        
        unordered_map<int,int>m;
        priority_queue<pair<int,int>>pq;
        
        for(auto x:b)
            m[x]++;
        
        for(auto x:m){
            pq.push({x.second,x.first});
        }
        
        int idx=0;
        
        while(!pq.empty()){
            
            auto cur=pq.top();
            pq.pop();
            int v=cur.first,k=cur.second;
            
            while(v--){
                
                if(idx>=n)idx=1;
                res[idx]=k;
                idx+=2;
                
            }
            
            
        }
        return res;
        
    }
};