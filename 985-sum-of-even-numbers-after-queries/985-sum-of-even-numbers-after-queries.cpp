class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>res(queries.size());
        int o=0,e=0;
        for(auto x:nums){
            if(x%2)
                o+=x;
            else
                e+=x;
        }
        int i=0;
        for(auto x:queries){
            int val=x[0],idx=x[1];
            if(nums[idx]%2==0){
                e-=nums[idx];
                nums[idx]+=val;
                if(nums[idx]%2)
                    o+=nums[idx];
                else
                    e+=nums[idx];
            }
            else{
                o-=nums[idx];
                nums[idx]+=val;
                if(nums[idx]%2)
                    o+=nums[idx];
                else
                    e+=nums[idx];
            }
            res[i++]=e;
        }
        return res;
    }
};