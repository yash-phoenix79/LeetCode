class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int mi=INT_MAX;
            int ma=INT_MIN;
            for(int j=i;j<n;j++){
                mi=min(mi,nums[j]);
                ma=max(ma,nums[j]);
                res+=(long long)(ma-mi);
                // cout<<nums[j]<<" ";
            }
            // cout<<endl;
        }
        return res;
        
    }
};