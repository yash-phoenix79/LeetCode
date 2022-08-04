class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int res=0;
        int t=max(start,goal);
        int cnt=0;
        while(t>0){
        cnt++;
            t/=2;
        }
        // cout<<cnt<<endl;
        while(cnt--)
        {
            int t1=start&1;
            int t2=goal&1;
            // cout<<t1<<" "<<t2<<endl;
            res+=(t1^t2);
            start=start>>1;
            goal=goal>>1;
        }
        return res;
    }
};