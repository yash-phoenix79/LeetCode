class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            while(nums[i]-1<nums.size()&&nums[i]!=i+1&&nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }
        
        vector<int>ans;
        
        for(int i=0;i<nums.size();i++)
        if(nums[i]!=i+1)
            ans.push_back(i+1);
        
        return ans;
    }
};