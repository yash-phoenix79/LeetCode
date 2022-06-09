class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int>ans;
       unordered_set<int>s;
        
         for(int i=1;i<=nums.size();i++)
            s.insert(i);
        
        for(int i=0;i<nums.size();i++)
            s.erase(nums[i]);
         
       
        for(auto x:s)
           ans.push_back(x);
        return ans;
    }
};