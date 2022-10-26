class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        int sum=0;
        unordered_map<int,int>m;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum%k==0&&i>0)
                return true;
            if(m.find(sum%k)!=m.end()&&i-m[sum%k]>1)
                return true;
            else if(m.find(sum%k)==m.end())
            m[sum%k]=i;
        }
        return false;
    }
};