class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>t;
        while(nums.size()!=1){
            t=vector<int>(nums.size()-1);
            for(int i=0;i<nums.size()-1;i++)
            t[i]=(nums[i]+nums[i+1])%10;
                        // cout<<nums.size()<<endl;
            nums=t;

        }
        return nums[0];
        
    }
};