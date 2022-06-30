class Solution {
public:
    int minMoves(vector<int>& nums) {
    
        int n=nums.size();
        int mini=*min_element(begin(nums),end(nums));
        
        int res=0;
        for(auto i:nums)
            res+=(i-mini);
        
        return res;
    
    }
};