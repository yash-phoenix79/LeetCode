class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int res=INT_MIN;
        
        int i=0,j=n-1;
        while(i<n/2){
            int s=nums[i++]+nums[j--];
            res=max(res,s);
        }
        return res;
        
    }
};