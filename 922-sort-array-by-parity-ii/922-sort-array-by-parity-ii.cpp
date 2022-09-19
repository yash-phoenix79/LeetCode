class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        vector<int>e,o;
        for(auto x:nums){
            if(x%2==0)
                e.push_back(x);
            else
                o.push_back(x);
        }
        int k=0;
        for(int i=0;i<nums.size()/2;i++)
        {
            nums[k++]=e[i];
            nums[k++]=o[i];
        }
        return nums;
    }
};