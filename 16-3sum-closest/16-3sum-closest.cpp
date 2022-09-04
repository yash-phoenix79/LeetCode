class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
     
        int n=nums.size();
        int mini=INT_MAX;
        int res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int l=i+1;
            int r=n-1;
            int t=target-nums[i];
            while(l<r){
                int s=nums[l]+nums[r];
                if(abs(s-t)==0)
                    return target;
                else if(abs(s-t)<mini){
                    mini=abs(s-t);
                    res=s+nums[i];
                    if(s<t)
                        l++;
                    else
                        r--;
                }
                else if(s<t)
                    l++;
                else
                    r--;
            }
        }
        return res;
    }
};