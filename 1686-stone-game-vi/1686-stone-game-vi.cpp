class Solution {
public:
    int stoneGameVI(vector<int>& al, vector<int>& bo) {
        
        int n=al.size();
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<n;i++)
            pq.push({al[i]+bo[i],i});
        
        int t=0;
        
        int a=0,b=0;
        
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            if(t==0)
                a+=al[cur.second];
            else
                b+=bo[cur.second];
            t^=1;
        }
        
        if(a==b)
            return 0;
        else if(a>b)
            return 1;
        else
            return -1;
        
    }
};