class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        int n=nums.size();
        if(n<3)
            return true;
        int i=1;
        for(i=1;i<n;i++){
            if(nums[i-1]>nums[i])
                break;
        }
        if(i==n)
            return true;
        
        for(i=n-2;i>=0;i--){
            if(nums[i+1]>nums[i])
                break;
        }
        
        if(i==-1)
            return true;
        
        return false;
        
    }
};