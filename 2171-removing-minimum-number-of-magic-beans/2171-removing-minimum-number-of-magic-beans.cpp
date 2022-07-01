class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        
        long long res=LONG_MAX,n=beans.size(),sum=0;
        
        sort(begin(beans),end(beans));
        
        for(int i:beans)
            sum+=i;
        
        for(int i=0;i<n;i++){
            res=min(res,sum-(n-i)*beans[i]);
        }
        
        return res;
        
    }
};