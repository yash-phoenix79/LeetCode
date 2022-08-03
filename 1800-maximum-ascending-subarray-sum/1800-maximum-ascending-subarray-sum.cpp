class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        
        int res=0;
        int i=1;
        
        if(n==1)
            return nums[0]; 
        
        while(i<n){
            int cnt=nums[i-1];
            while(i<n&&nums[i]>nums[i-1]){
                cnt+=nums[i];
                i++;
            }
            res=max(res,cnt);
           
            i++;
        }
        return res;
    }
};