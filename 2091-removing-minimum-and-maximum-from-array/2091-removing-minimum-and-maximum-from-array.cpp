class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n=nums.size();
        int a=max_element(begin(nums),end(nums))-begin(nums);
        int b=min_element(begin(nums),end(nums))-begin(nums);
        
        if(a>b)
            swap(a,b);
        
        return min(b+1,min(n-a,a+1+n-b));
        
    }
};