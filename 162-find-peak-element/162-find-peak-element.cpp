class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       int n=nums.size();
        
        if(n==1)
            return 0;
        if(n==2)
            return nums[0]>nums[1]?0:1;
        
        int l=0,r=n-1,m;
        
        while(l<r){
            m=(l+r)/2;
            if(m-1>=0&&nums[m-1]<nums[m]&&m+1<n&&nums[m+1]<nums[m])
                return m;
            else if(nums[m]<nums[m+1])
                l=m+1;
            else
                r=m;
        }
        return l;
    }
};