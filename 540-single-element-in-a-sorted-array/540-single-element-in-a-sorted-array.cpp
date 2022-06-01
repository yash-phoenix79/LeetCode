class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        
        int l=0,r=n-1;
        int m;
        while(l<r){
            m=(l+r)/2;
            
            if(m-1>=0&&nums[m-1]<nums[m]&&m+1<n&&nums[m+1]>nums[m])
                return nums[m];
            else if(m-1>=0&&nums[m]==nums[m-1]){
                if(m%2)l=m+1;
                else r=m-2;
                    
            }
            else if(m+1<n&&nums[m]==nums[m+1]){
                if(m%2)r=m-1;
                else l=m+2;
            }
            
        }
        return nums[l];
    }
};