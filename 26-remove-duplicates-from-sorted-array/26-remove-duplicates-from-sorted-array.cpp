class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n=nums.size();
        int idx=0,cur=idx+1;
        while(cur<n){
            while(cur<n&&nums[cur]==nums[cur-1])
                cur++;
            if(cur>=n&&nums[idx]!=nums[cur-1])
                nums[++idx]=nums[n-1];
            else if(cur<n)
           nums[++idx]=nums[cur++];
            
        }
        
        nums.resize(idx+1);
      
        return idx+1;
    }
};