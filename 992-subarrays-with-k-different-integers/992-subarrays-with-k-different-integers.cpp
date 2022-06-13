class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        int ans=0;
        for(auto i=0,j=0,cnt=0,prefix=0;i<n;i++){
            if(m[nums[i]]++==0)cnt++;
            if(cnt>k)m[nums[j++]]--,cnt--,prefix=0;
            while(m[nums[j]]>1) m[nums[j++]]--,prefix++;
            if(cnt==k)  ans+=(1+prefix);  
        }
        return ans;
    }
};