class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            
            while(nums[i]<n&&i!=nums[i]){
                swap(nums[i],nums[nums[i]]);
            }
            
        }
        int ans=n;
        for(int i=0;i<n;i++){
            if(i!=nums[i])
            {
                ans=i;
                break;
            }
        }
        return ans;
    }
};