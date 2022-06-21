class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        
        int n=h.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int i;
        for(i=0;i<n-1;i++){
            if(h[i+1]-h[i]>0){
                pq.push(h[i+1]-h[i]);}
            
                if(pq.size()>ladders)
                {
                    if(pq.top()<=bricks){
                        bricks-=pq.top();
                        pq.pop();
                    }
                    else
                        break;
                
            }
        }
        return i;
    }
};