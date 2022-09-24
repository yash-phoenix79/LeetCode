class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& div) {
        
        int n=nums.size(),m=div.size();
        
        int hcf=div[0];
        for(int i=1;i<m;i++)
        {
            hcf=gcd(hcf,div[i]);
        }
        
        sort(begin(nums),end(nums));
        
        if(nums[0]>hcf)
            return -1;
        
        int i=0;
        while(i<n&&nums[i]<hcf&&hcf%nums[i]!=0)
            i++;
        if(i==n)
            return -1;
            return i;
        
    }
};