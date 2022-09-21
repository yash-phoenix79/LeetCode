class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        int sum=0,res=0;
        m[0]=1;
        for(auto x:nums){
            x%=2;
            sum+=x;
            if(m.find(sum-k)!=m.end())
                res+=m[sum-k];
            m[sum]++;
        }
        return res;
        
    }
};