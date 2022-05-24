class Solution {
public:
    
    void findSubsets(int idx,int n,vector<int>temp, set<vector<int>>&s,vector<int>& nums){
        if(idx==n){
           sort(temp.begin(),temp.end());
            s.insert(temp);
            return;
        }
          findSubsets(idx+1,n,temp,s,nums);
        temp.push_back(nums[idx]);
        findSubsets(idx+1,n,temp,s,nums);
        
        
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>>s;
        vector<int>temp;
        
        int n=nums.size();
        findSubsets(0,n,temp,s,nums);
        
        
        for(auto x:s)
        ans.push_back(x);
        return ans;
    }
};