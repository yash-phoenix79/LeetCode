class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int i=0,maxReachable=0,lastReached=0,step=0;
        
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