class Solution {
public:
    int maxProfit(vector<int>& p) {
     
        int n=p.size();
        for(int i=n-1;i>0;i--)
            p[i]-=p[i-1];
        
        int res=0,sum=0;
        
        for(int i=1;i<n;i++){
            sum+=p[i];
            res=max(res,sum);
            if(sum<0)
                sum=0;
        }
        return res;
    }
};