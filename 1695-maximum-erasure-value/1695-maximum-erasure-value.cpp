class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++)
            pref[i]=pref[i-1]+nums[i];
        
        vector<int>num(10e5+1,-1);
        int start=-1;
        int maxErs=0;
        
        for(int i=0;i<n;i++){
            if(num[nums[i]]>start)
                start=num[nums[i]];
            num[nums[i]]=i;
            if(start!=-1)
            maxErs=max(maxErs,pref[i]-pref[start]);
            else
                maxErs=max(maxErs,pref[i]);
        }
        
        return maxErs;
    }
};