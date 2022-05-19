class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        if(n<4)
            return ans;
        
        int t;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                t=target-nums[i]-nums[j];
                int left=j+1,right=n-1;
                while(left<right){
                    if(nums[left]+nums[right]==t){
                         s.insert({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                    }
                       
                    else if(nums[left]+nums[right]<t)
                        left++;
                    else
                        right--;
                }
                }
            }
        
        for(auto &x:s)
            ans.push_back(x);
       
        return ans;
        
    }
};