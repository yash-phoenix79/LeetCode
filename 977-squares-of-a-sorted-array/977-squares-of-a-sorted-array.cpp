class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size());
        
        int l=0,r=nums.size()-1,k=nums.size()-1;
        
        while(l<=r){
            if(abs(nums[l])>abs(nums[r]))ans[k--]=nums[l]*nums[l++];
            else ans[k--]=nums[r]*nums[r--];
        }
        return ans;
    }
};