class Solution {
public:
    
    void find(int idx,vector<int>& nums,vector<vector<int>>&res,vector<int>sol){
             int n=nums.size();
        if(sol.size()>1)
            res.push_back(sol);
        unordered_set<int>s;
        
        for(int i=idx;i<n;i++){
            if((sol.empty()||sol.back()<=nums[i])&&s.find(nums[i])==s.end()){
                sol.push_back(nums[i]);
                find(i+1,nums,res,sol);
                sol.pop_back();
                s.insert(nums[i]);
            }
        }
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        vector<int>sol;
        
        find(0,nums,res,sol);
        return res;
    }
};