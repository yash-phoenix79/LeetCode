class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n=nums.size();
        int i=0,idx=0;
        
        while(i<n){
            if(nums[i]!=val)
                nums[idx++]=nums[i];
            i++;
        }
        nums.resize(idx);
        return idx;
        
    }
};