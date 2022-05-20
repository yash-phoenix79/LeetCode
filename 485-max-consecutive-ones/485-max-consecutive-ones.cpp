class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int ans=0,i=0;
         int cnt;
       
        while(i<nums.size()){
         cnt=0;
            while(i<nums.size()&&nums[i]==1)
            {
                cnt++;
                i++;
            }
            ans=max(ans,cnt);
            i++;
        }
        return ans;
    }
};