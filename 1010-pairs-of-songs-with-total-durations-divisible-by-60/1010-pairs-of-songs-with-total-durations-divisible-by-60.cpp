class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        int n=time.size();
        vector<int>cnt(60,0);
        int res=0,t;
        
        for(int i=0;i<n;i++){
            t=time[i]%60;
            if(t==0)
                res+=cnt[0];
            else
                res+=cnt[60-t];
            cnt[t]++;
        }
        
        return res;
        
    }
};