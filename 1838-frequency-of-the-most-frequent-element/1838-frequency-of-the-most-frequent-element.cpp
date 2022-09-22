class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(begin(nums),end(nums));
        int i=0,j,res=0,n=nums.size();
        long long sum=0;
        
        for(j=0;j<n;j++){
            sum+=nums[j];
            if(k+sum<(long)(j-i+1)*nums[j])
                sum-=nums[i++];
            
        }
        return n-i;
    }
};