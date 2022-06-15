class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        int cur,ans=INT_MIN;
        
        deque<int>q;
        for(int i=0;i<n;i++)
        {
            while(!q.empty()&&q.front()+k<i)
                q.pop_front();
            cur=nums[i]+(q.empty()?0:nums[q.front()]);
            while(!q.empty()&&nums[q.back()]<=cur)
                q.pop_back();
            ans=max(ans,cur);
            if(cur>=0)
                q.push_back(i);
            nums[i]=cur;
        }
        return ans;
    }
};