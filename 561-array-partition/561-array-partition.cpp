class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        sort(begin(nums),end(nums));
        for(int i=0;i<n;i+=2)
            sum+=nums[i];
        return sum;
    }
};