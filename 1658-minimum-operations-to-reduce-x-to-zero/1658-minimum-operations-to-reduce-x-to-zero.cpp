class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        
        int sum=0;
        for(int i:nums)
            sum+=i;
        int ans=0;
        if(sum==x)
            return n;
        bool found=false;
        sum-=x;
        int t=0;
        int i=0,j;
        for(int j=0;j<n;j++){
            t+=nums[j];
            while(i<=j&&t>sum)
                t-=nums[i++];
            if(t==sum){
                found=true;
                ans=max(ans,j-i+1);
            }
        }
        return found?n-ans:-1;
    }
};