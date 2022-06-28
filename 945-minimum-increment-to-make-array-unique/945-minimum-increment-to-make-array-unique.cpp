class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        
        int n=nums.size();
        
        int prev=-1;
        int res=0;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            prev=max(prev+1,nums[i]);
            res+=(prev-nums[i]);
        }
        return res;
    }
};