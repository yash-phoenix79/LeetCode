class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        
        for(int i=0;i<n;i++)
            nums[i]%=2;
        
        m[0]=1;
        int sum=0,res=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(m.find(sum-k)!=m.end())
               res+=m[sum-k];
            m[sum]++;
        }
        
        return res;
        
    }
};