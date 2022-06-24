class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        if(target.size()==1)
            return target[0]==1;
        
        long tot=0;
        priority_queue<int>pq(target.begin(),target.end());
        for(auto x:target)
        {
            tot+=x;
        }
        
        while(pq.top()!=1){
            int cur=pq.top();
            pq.pop();
            if(tot-cur==1)
                return true;
            int x=cur%(tot-cur);
            
            if(x==0||x==cur)
                return false;
            tot=tot-cur+x;
            pq.push(x);
            
        }
        return true;
    }
};