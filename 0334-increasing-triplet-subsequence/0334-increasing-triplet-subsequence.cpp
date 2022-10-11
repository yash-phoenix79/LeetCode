class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n=nums.size();
        int fir=INT_MAX,sec=INT_MAX;
        
        for(auto x:nums){
            if(x<=fir)
                fir=x;
            else if(x<=sec)
                sec=x;
            else
                return true;
        }
        return false;
        
    }
};