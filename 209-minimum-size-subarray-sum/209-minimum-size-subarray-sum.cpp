class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=nums.size(),n=nums.size();
        
        int sum=0;
        for(int i:nums)
            sum+=i;
        if(sum<target)
            return 0;
        
        int i=0,j=0,t=0;
        
        for(j=0;j<n;j++){
            t+=nums[j];
            // if(t>=target)
            //     ans=min(ans,j-i+1);
            while(i<=j&&t>=target){
                ans=min(ans,j-i+1);
                t-=nums[i++];
            }
        }
        return ans;
    }
};