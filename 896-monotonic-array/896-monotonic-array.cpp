class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool in=true,dec=true;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1])dec=false;
            if(nums[i]<nums[i-1])in=false;
            if(!dec&&!in)return false;
        }
        return true;
    }
};