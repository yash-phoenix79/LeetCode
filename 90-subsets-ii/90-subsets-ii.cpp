class Solution {
public:
    void findSets(vector<int>& nums,int idx,vector<int>ds, vector<vector<int>>&ans){
        ans.push_back(ds);
        for(int i=idx;i<nums.size();i++){
            if(i!=idx&&nums[i]==nums[i-1])continue;
            ds.push_back(nums[i]);
            findSets(nums,i+1,ds,ans);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        findSets(nums,0,ds,ans);
        return ans;
    }
};