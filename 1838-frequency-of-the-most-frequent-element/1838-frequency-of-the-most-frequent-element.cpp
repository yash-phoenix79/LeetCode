class Solution {
public:
    int maxFrequency(vector<int>& nums, long k) {
        sort(begin(nums),end(nums));
        int res=0;
        int i=0,j;
        
        for(j=0;j<nums.size();j++){
            k+=nums[j];
            if(k<(long)nums[j]*(j-i+1))
                k-=nums[i++];
            res=max(res,j-i+1);
        }
        return res;
    }
};