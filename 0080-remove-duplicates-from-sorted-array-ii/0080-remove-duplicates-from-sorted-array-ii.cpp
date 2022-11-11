class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     
        int i=0,cur=1,k=1;
        int n=nums.size();
        while(cur<n){
            k=1;
            while(cur<n&&nums[cur]==nums[cur-1]){
                cur++;
                k++;
                if(k==2)
                    nums[++i]=nums[cur-1];
            }
            
            if(cur>=n&&nums[i]!=nums[cur-1])
                nums[++i]=nums[cur-1];
            else if(cur<n)
                nums[++i]=nums[cur++];
        }
        
        nums.resize(i+1);
        return i+1;
        
    }
};