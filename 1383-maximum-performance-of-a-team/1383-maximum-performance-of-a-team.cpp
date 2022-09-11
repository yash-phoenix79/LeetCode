class Solution {
public:
    int maxPerformance(int n, vector<int>& sp, vector<int>& ef, int k) {
        vector<pair<int,int>>eng;
        
        for(int i=0;i<n;i++)
        eng.emplace_back(ef[i],sp[i]);
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        long sum=0,ans=0;
        
        sort(rbegin(eng),rend(eng));
        
        for(auto &[e,s]:eng){
            sum+=s;
            pq.emplace(s);
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            ans=max(ans,e*sum);
        }
       return ans % (int) (1e9 + 7);
    }
};