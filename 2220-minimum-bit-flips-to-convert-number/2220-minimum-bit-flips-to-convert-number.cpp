class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int res=0;
       
      
        // cout<<cnt<<endl;
        while(start!=0||goal!=0)
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