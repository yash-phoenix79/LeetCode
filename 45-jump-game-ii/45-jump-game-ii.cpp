class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int lastReached=0,maxReachable=0;
        int step=0,i=0;
        while(lastReached<n-1){
            maxReachable=max(maxReachable,i+nums[i]);
            if(i==lastReached){
                lastReached=maxReachable;
                step++;
            }
            i++;
        }
        return step;
    }
};