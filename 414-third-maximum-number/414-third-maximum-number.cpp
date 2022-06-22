class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        long one=LONG_MIN,two=LONG_MIN,thr=LONG_MIN;
        
        for(int i:nums){
            if(i==one||i==two||i==thr)
                continue;
            if(i>one){
                thr=two;
                two=one;
                one=i;
            }
            else if(i>two){
               thr=two;
                two=i;
            }
            else if(i>thr)
                thr=i;
        }
        
        return thr==LONG_MIN?one:thr;
        
    }
};