class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int n=nums.size();
        int sum=0,maxSum=0,res=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxSum=max(maxSum,sum);
            if(sum<0)
                sum=0;
            nums[i]=-nums[i];
        }
        
        res=maxSum;
        maxSum=0,sum=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxSum=max(maxSum,sum);
            if(sum<0)
                sum=0;
            nums[i]=-nums[i];
        }
        res=max(res,maxSum);
        return res;
    }
};