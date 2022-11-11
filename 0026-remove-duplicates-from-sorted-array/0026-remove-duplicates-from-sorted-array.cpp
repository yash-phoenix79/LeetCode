class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i=0,cur=1;
        int n=nums.size();
        
        while(cur<n){
            while(cur<n&&nums[cur]==nums[cur-1])
                cur++;
            if(cur>=n&&nums[i]!=nums[cur-1])
                nums[++i]=nums[cur-1];
            else if(cur<n)
                nums[++i]=nums[cur++];
        }
        
        nums.resize(i+1);
        return i+1;
        
    }
};