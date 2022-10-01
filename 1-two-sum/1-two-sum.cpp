class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            if(m.find(nums[i])!=m.end()){
                return {i,m[nums[i]]};
            }
            m[tar-nums[i]]=i;
        }
        return {};
    }
};