class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        
        for(int i=0;i<stones.size();i++)
            pq.push(stones[i]);
        
        int fir,sec;
        while(pq.size()>1){
            fir=pq.top();
            pq.pop();
            sec=pq.top();
            pq.pop();
            
            if(fir!=sec)
                pq.push(fir-sec);
            
        }
      if(!pq.empty())
          return pq.top();
        return 0;
    }
};