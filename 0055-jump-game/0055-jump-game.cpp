class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        
        int i=0,j=0;
        
        for(i=0;i<n&&i<=j;i++){
            
            j=max(j,i+nums[i]);
            
        }
            
        return i==n;
        
    }
};