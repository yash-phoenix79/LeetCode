class Solution {
public:
    int nthUglyNumber(int n) {
        
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_set<long long>s;
        pq.push(1);
        s.insert(1);
        long long t;
        while(n>0){
            
            t=pq.top();
            pq.pop();
            if(s.find(2*t)==s.end()&&2*t<INT_MAX){
                pq.push(2*t);
                s.insert(2*t);
            }
            
            if(s.find(3*t)==s.end()&&3*t<INT_MAX){
                pq.push(3*t);
                s.insert(3*t);
            }
            if(s.find(5*t)==s.end()&&5*t<INT_MAX){
                pq.push(5*t);
                s.insert(5*t);
            }
            
            n--;
        }
        
        return t;
        
    }
};