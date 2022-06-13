class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int n=nums.size();
        if(k==0)
            return false;
        if(k>=n)
            k=nums.size()-1;
        
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            if(i>k)s.erase(nums[i-k-1]);
            if(s.find(nums[i])!=s.end())return true;
            s.insert(nums[i]);
        }
        return false;
    }
};