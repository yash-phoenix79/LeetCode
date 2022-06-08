class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        long cur=0;
        deque<int>q;
        
        for(int i=0;i<nums.size();i++){
           
            while(!q.empty()&&q.front()+k<i)
                q.pop_front();
             cur=nums[i]+(q.empty()?0:nums[q.front()]);
            while(!q.empty()&&cur>=nums[q.back()])
                q.pop_back();
            
            q.push_back(i);
            nums[i]=cur;
            
        }
        return cur;
    }
};