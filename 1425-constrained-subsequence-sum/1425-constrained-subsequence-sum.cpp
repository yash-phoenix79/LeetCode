class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int cur,ans=INT_MIN;
        deque<int>q;
        
        for(int i=0;i<nums.size();i++){
            if(!q.empty()&&q.front()+k<i)
                q.pop_front();
            cur=nums[i]+(q.empty()?0:nums[q.front()]);
            while(!q.empty()&&cur>=nums[q.back()])
                q.pop_back();
            ans=max(ans,cur);
            if(cur>0)
            q.push_back(i);
            nums[i]=cur;
        }
        return ans;
    }
};