class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        int lSum=0,rSum=0;
        for(int i=0;i<n;i++)
            rSum+=nums[i];
        for(int i=0;i<n;i++){
            rSum-=nums[i];
            if(lSum==rSum)return i;
            lSum+=nums[i];
        }
        return -1;
        
    }
};