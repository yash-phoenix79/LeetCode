class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0,reach=0;
        int n=nums.size();
        for(;i<=reach&&i<n;i++){
            reach=max(reach,i+nums[i]);
        }
        return i==n;
    }
};