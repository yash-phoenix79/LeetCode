class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
       int less=0,cnt=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<target)
                less++;
            else if(nums[i]==target)
              cnt++;
        }
        vector<int> res;
        for(int i=1;i<=cnt;i++){
            res.push_back(less+i-1);
        }
        return res;
    }
};