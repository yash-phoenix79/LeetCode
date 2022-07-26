class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
       long long int rSum=0,lSum=0;
        
        for(int i=0;i<n;i++){
            rSum+=nums[i];
        }
        
        int cnt=0;
        for(int i=0;i<n-1;i++){
            rSum-=nums[i];
            lSum+=nums[i];
            if(lSum>=rSum)
                cnt++;
        }
        return cnt;
    }
};