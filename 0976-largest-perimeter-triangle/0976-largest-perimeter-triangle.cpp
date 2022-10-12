class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        int n=nums.size();
        sort(begin(nums),end(nums));
        
        int i=n-1;
        while(i>=2){
          if(nums[i-1]+nums[i-2]>nums[i])
              return nums[i]+nums[i-1]+nums[i-2];
                
                i--;
        }
        return 0;
    }
};