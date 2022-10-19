class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n=nums.size();
        if(n<3)
        return 0;
        int res=0,pre=nums[1]-nums[0],ind=0;
        
        for(int i=1;i<n-1;i++){
            
            if(nums[i+1]-nums[i]==pre){
                ind++;
            }
            else{
                pre=nums[i+1]-nums[i];
                ind=0;
            }
            res+=ind;
        }
        return res;
    }
};