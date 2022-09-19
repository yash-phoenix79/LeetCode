class Solution {
public:
    int countElements(vector<int>& nums) {
        
        if(nums.size()<3)
            return 0;
        
        int maxi=*max_element(begin(nums),end(nums));
        int mini=*min_element(begin(nums),end(nums));
        
        int c1=count(begin(nums),end(nums),maxi);
        int c2=count(begin(nums),end(nums),mini);
        
        int res=nums.size()-c1-c2;
        if(res>0)
            return res;
        return 0;
        
    }
};