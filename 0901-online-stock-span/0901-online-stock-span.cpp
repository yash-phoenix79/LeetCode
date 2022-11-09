class StockSpanner {
public:

    stack<pair<int,int>>s;    
    StockSpanner() {
        
    }
    
    int next(int p) {
        
        int cnt=1;
        
        while(!s.empty()&&p>=s.top().first)
        {
            cnt+=s.top().second;
            s.pop();
        }
        s.push({p,cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */