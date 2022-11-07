class Solution {
public:
    int maximumScore(int a, int b, int c) {
        
        int res=0;
        priority_queue<int>pq;
        
        pq.push(a);
         pq.push(b);
         pq.push(c);
        
        while(1){
           
            int x=pq.top();
            pq.pop();
            
            int y=pq.top();
            pq.pop();
            
            if(x==0||y==0)break;
             res++;
            pq.push(--x);
            pq.push(--y);
        }
        return res;
        
    }
};