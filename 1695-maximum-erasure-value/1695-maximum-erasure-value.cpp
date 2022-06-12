class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size(),sum=0;
        unordered_set<int>s;
       int ans=0;
        for(int i=0,j=0;i<n;i++){
            while(s.find(nums[i])!=s.end()){
                s.erase(nums[j]);
                ans-=nums[j++];
            }
            s.insert(nums[i]);
            ans+=nums[i];
            sum=max(sum,ans);
        }
        return sum;
    }
};