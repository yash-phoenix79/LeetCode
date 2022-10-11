class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n=nums.size();

        vector<int>l(n),r(n);
        l[0]=nums[0];
        
        
        
        for(int i=1;i<n;i++){
            l[i]=min(nums[i],l[i-1]);
        }
        
        r[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            r[i]=max(nums[i],r[i+1]);
        
        for(int i=1;i<n-1;i++)
            if(nums[i]>l[i-1]&&nums[i]<r[i+1])
                return true;
        return false;
        
    }
};