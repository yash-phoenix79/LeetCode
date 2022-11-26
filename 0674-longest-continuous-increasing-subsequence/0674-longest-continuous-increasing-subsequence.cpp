class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        
        int res=1,cnt=1;
        int n=nums.size();
        
        int i=1;
        while(i<n){
            
            if(nums[i]>nums[i-1]){
                cnt++;
                res=max(res,cnt);
            }
            else{
                cnt=1;
            }
            i++;
        }
        return res;
    }
};