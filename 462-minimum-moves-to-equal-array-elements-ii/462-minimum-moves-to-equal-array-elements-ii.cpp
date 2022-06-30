class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int med=nums[n/2];
        int res=0;
       for(auto i:nums)
           res+=abs(i-med);
        return res;
    }
};