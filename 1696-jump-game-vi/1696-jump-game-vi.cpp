class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        long cnt=0;
        deque<int>q;
        for(int i=0;i<n;i++){
            cnt=nums[i]+(q.empty()?0:nums[q.front()]);
            while(!q.empty()&&cnt>=nums[q.back()])
                q.pop_back();
            q.push_back(i);
            if(q.front()==i-k)
                q.pop_front();
            nums[i]=cnt;
        }
        return nums[n-1];
    }
};