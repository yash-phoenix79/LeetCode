class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>res(queries.size());
        int e=0;
        for(auto x:nums){
         if(x%2==0)
                e+=x;
        }
        int i=0;
        for(auto x:queries){
            int val=x[0],idx=x[1];
            if(nums[idx]%2==0)
                e-=nums[idx];
                nums[idx]+=val;
                if(nums[idx]%2==0)
                    e+=nums[idx];
            res[i++]=e;
          
        }
        return res;
    }
};