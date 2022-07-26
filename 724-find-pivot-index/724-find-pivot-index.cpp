class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n=nums.size();
        int rSum=0;
        
        for(int i=0;i<n;i++)
            rSum+=nums[i];
        
        int lSum=0;
        
        for(int i=0;i<n;i++){
            rSum-=nums[i];
            if(lSum==rSum)return i;
            lSum+=nums[i];
        }
        return -1;
    }
};