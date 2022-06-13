class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>hash(n+1,0);
        int ans=0;
        for(int i=0,j=0,cnt=0,pref=0;i<n;i++){
            if(hash[nums[i]]++ ==0) cnt++;
            if(cnt>k)hash[nums[j++]]--,cnt--,pref=0;
            while(hash[nums[j]]>1)hash[nums[j++]]--,pref++;
            if(cnt==k)ans+=(1+pref);
        }
        return ans;
    }
};