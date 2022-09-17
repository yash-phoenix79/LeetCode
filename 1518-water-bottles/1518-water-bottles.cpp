class Solution {
public:
    int numWaterBottles(int numB, int numE) {
        
        int res=0;
        int cnt1=numB;
        int cnt2=0;
        
        while(cnt1+cnt2>=numE){
            res+=cnt1;
            int t=(cnt1+cnt2);
            cnt1=t/numE;
            cnt2=t%numE;
        }
        
        res+=cnt1;
        return res;
    }
};