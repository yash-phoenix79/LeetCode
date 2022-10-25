class Solution {
public:
    
    int atmost(vector<int>&nums,int k){
        
        int n=nums.size();
        int i=0,j=0;
        int res=0;
        
        for(;j<n;j++){
            k-=nums[j]%2;
            while(k<0)
                k+=nums[i++]%2;
            res+=(j-i+1);
        }
        return res;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n=nums.size();
        return atmost(nums,k)-atmost(nums,k-1);
        
    }
};