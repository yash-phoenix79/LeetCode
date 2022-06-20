class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        
        int t;
        while(q.size()!=1){
            t=k-1;
            while(t--){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};