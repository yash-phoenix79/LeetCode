class Solution {
public:
    int search(vector<int>& nums, int target) {
      
        if(nums.size()==0)
        return -1;
        
        int n=nums.size();
        int l=0,h=n-1;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
               l=mid+1;
            else 
                h=mid-1;
        }
        return -1;
    }
};