class Solution {
public:
   set<vector<int>>res;
    vector<vector<int>>ans;
    
    void find(int i,vector<int>&nums,vector<int>sol){
        int n=nums.size();
        if(i>=n){
            if(sol.size()>1){
               
                    res.insert(sol);
            }
                
            return;
        }
            
        if(sol.empty()||sol.back()<=nums[i]){
            find(i+1,nums,sol);
            sol.push_back(nums[i]);
            find(i+1,nums,sol);
            sol.pop_back();
        }
        
        else
            find(i+1,nums,sol);
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>sol;
        find(0,nums,sol);
        
        for(auto x:res)
            ans.push_back(x);
        
        return ans;
    }
};